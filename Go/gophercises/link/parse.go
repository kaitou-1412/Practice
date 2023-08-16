package link

import (
	"io"
	"strings"

	"golang.org/x/net/html"
)

// Link represents a link (<a href="...">)
// in an HTML document
type Link struct {
	Href string
	Text string
}

// Parse will take in an HTML document and
// will return a slice of links parsed from it.
func Parse(r io.Reader) ([]Link, error) {
	doc, err := html.Parse(r)
	if err != nil {
		return nil, err
	}
	// 1. Find <a> nodes in the document
	nodes := linknodes(doc) 
	var links []Link
	// 2. for each link node...
	for _, node := range nodes {
		// 	 2.a build a link
		links = append(links, buildLink(node))
	}
	// 3. return the links  
	return links, nil 
} 

func linknodes(n *html.Node) []*html.Node {
	if n.Type == html.ElementNode && n.Data == "a" {
		return []*html.Node{n}
	}
	var ret []*html.Node
	for c := n.FirstChild; c != nil; c = c.NextSibling {
		ret = append(ret, linknodes(c)...)
	}
	return ret
}

func buildLink(n *html.Node) Link {
	var ret Link
	for _, attr := range n.Attr {
		if attr.Key == "href" {
			ret.Href = attr.Val
			break
		}
	}
	ret.Text = text(n)
	return ret 
}

func text(n *html.Node) string {
	if n.Type == html.TextNode {
		return n.Data
	}
	if n.Type != html.ElementNode {
		return ""
	}
	var ret string
	for c := n.FirstChild; c != nil; c = c.NextSibling {
		ret += text(c)
	}  
	return strings.Join(strings.Fields(ret), " ") 
}
