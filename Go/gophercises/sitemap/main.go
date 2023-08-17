package main

import (
	"encoding/xml"
	"flag"
	"fmt"
	"io"
	"link/link"
	"net/http"
	"net/url"
	"os"
	"strings"
)

/*
	1. GET the web page
	2. Parse all the links on the page
	3. Build proper URLs with our links
	4. Filter out any links w/a different domain
	5. Find all the pages (BFS)
	6. Print out XML
*/

const xmlns = "http://www.sitemaps.org/schemas/sitemap/0.9"

type loc struct {
	Value string `xml:"loc"`
}

type urlset struct {
	Urls []loc `xml:"url"`
	Xmlns string `xml:"xmlns,attr"`
}

func main() {
	urlFlag := flag.String("url", "https://gophercises.com", "the url that you want to build a sitemap for")
	maxDepth := flag.Int("depth", 3, "the maximum number of links deep to traverse")
 	flag.Parse()
	
	pages := bfs(*urlFlag, *maxDepth)
	// for _, page := range pages {
	// 	fmt.Println(page)
	// }
	toXml := urlset{
		Urls: make([]loc, len(pages)),
		Xmlns: xmlns,
	}
	for i, page := range pages {
		toXml.Urls[i] = loc{page}
	}   
	enc := xml.NewEncoder(os.Stdout)
	enc.Indent("", "  ")
	fmt.Print(xml.Header)
	err := enc.Encode(toXml)
	handleError(err, "could not encode xml") 
	fmt.Println() 
} 

func handleError(err error, msg ...string) {
	if err != nil {
		fmt.Println(strings.Join(msg, " "))
		os.Exit(1)
	}
}

func getBase(resp *http.Response) string {
	reqURL := resp.Request.URL
	baseUrl := &url.URL{
		Scheme: reqURL.Scheme,
		Host: reqURL.Host,
	}
	base := baseUrl.String()
	return base
}

func getHrefs(r io.Reader, base string) []string {
	var ret []string
	links, err := link.Parse(r)
	handleError(err, "could not parse links")
	for _, l := range links {
		/*
			1. /some-path
			2. https://gophercises.com/some-path
			3. #fragment (skip)
			4. mailto:jon@calhoun.io (skip)
		*/
		switch {
		case strings.HasPrefix(l.Href, "/"):
			ret = append(ret, base + l.Href)
		case strings.HasPrefix(l.Href, "http"):
			ret = append(ret, l.Href)
		}
	}
	return ret
}

func filter(links []string, keepFn func(string) bool) []string {
	var ret []string
	for _, l := range links {
		if keepFn(l) {
			ret = append(ret, l)
		}
	} 
	return ret
}

func withPrefix(pfx string) func(string) bool {
	return func(l string) bool {
		return strings.HasPrefix(l, pfx)
	}
}

func get(urlStr string) []string {
	resp, err := http.Get(urlStr)
	handleError(err, "could not get the requested page:", urlStr)
	defer resp.Body.Close()
	base := getBase(resp)
	return filter(getHrefs(resp.Body, base), withPrefix(base))
}

func bfs(urlStr string, maxDepth int) []string {
	seen := make(map[string]struct{})
	var q map[string]struct{}
	nq := map[string]struct{}{
		urlStr: struct{}{},
	}
	for i := 0; i <= maxDepth; i++ {
		q, nq = nq, make(map[string]struct{})
		if len(q) == 0 {
			break 
		} 
		for url := range q {
			if _, ok := seen[url]; ok {
				continue
			}
			seen[url] = struct{}{}
			for _, l := range get(url) {
				if _, ok := seen[l]; !ok {
					nq[l] = struct{}{}
				}
			}
		}
	}
	ret := make([]string, 0, len(seen))
	for url := range seen {
		ret = append(ret, url)
	}
	return ret  
}
