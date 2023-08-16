package main

import (
	"flag"
	"fmt"
	"link"
	"os"
	"strings"
)

var exampleHtml = `
<html>
<body>
  <h1>Hello!</h1>
  <a href="/other-page">
  A link to another page 
  <span>some span</span>
  </a>
  <a href="/second-page">
  A link to second page 
  </a>
</body>
</html>
`

func main() {
	// Get all the flags: filename, port 
	filename := flag.String("file", "examples/ex1.html", "the HTML example file")
	flag.Parse()
	fmt.Printf("Using the html in %s.\n", *filename)
	
	// Get the file object
	bs, err := os.ReadFile(*filename)
	handleError(err, "We couldn't open the file", *filename)
	r := strings.NewReader(string(bs))
	links, err := link.Parse(r)
	handleError(err, "could not parse html")
	fmt.Printf("%+v\n", links)  
}

func handleError(err error, msg ...string) {
	if err != nil {
		fmt.Println(strings.Join(msg, " "))
		os.Exit(1)
	}
}
