package main

import (
	"cyoa"
	"flag"
	"fmt"
	"html/template"
	"log"
	"net/http"
	"os"
	"strings"
)

func main() {
	// Get all the flags: filename, port 
	filename := flag.String("file", "gopher.json", "the JSON file with the CYOA story")
	port := flag.Int("port", 3000, "the port to start the CYOA web application on ")
	flag.Parse()
	fmt.Printf("Using the story in %s.\n", *filename)
	
	// Get the file object
	f, err := os.Open(*filename)
	handleError(err, "We couldn't open the file", *filename)
	
	// Get the json data
	story, err := cyoa.JsonStory(f)
	handleError(err, "We couldn't decode the json data")

	// Print out the data 
	
	// To keep default options
	// h := cyoa.NewHandler(story)
	
	// Passing custom template
	// tpl := template.Must(template.New("").Parse("Hello!"))
	// h := cyoa.NewHandler(story, cyoa.WithTemplate(tpl))

	// Passing custom pathFunc
	tpl := template.Must(template.New("").Parse(storyTmpl))
	h := cyoa.NewHandler(
		story, 
		cyoa.WithTemplate(tpl), 
		cyoa.WithPathFunc(pathFunc),
	)

	mux := http.NewServeMux()
	mux.Handle("/story/", h)
	fmt.Printf("Starting the server on port: %d\n", *port)
	log.Fatal(http.ListenAndServe(fmt.Sprintf(":%d", *port), mux))
}

func handleError(err error, msg ...string) {
	if err != nil {
		fmt.Println(strings.Join(msg, " "))
		os.Exit(1)
	}
}

func pathFunc(r *http.Request) string {
	path := strings.TrimSpace(r.URL.Path)
	if path == "/story" || path == "/story/" {
		path = "/story/intro"
	}
	return path[len("/story/"):]
}

var storyTmpl = `
<!DOCTYPE html>
<html lang="en"> 
<head>
	<meta charset="UTF-8" />
	<meta name="viewport" content="width=device-width, initial-scale=1.0" />
	<title>Choose Your Own Adventure</title>
</head>
<body>
	<section class="page">
		<h1>{{.Title}}</h1>
		{{range .Paragraphs}}
		<p>{{.}}</p>
		{{end}}
		<ul>
		{{range .Options}}
		<li><a href="/story/{{.Arc}}">{{.Text}}</a></li>
		{{end}}
		</ul>
	</section>
	<style>
		body {
			font-family: helvetica, arial;
		}
		h1 {
			text-align: center;
			position: relative;
		}
		.page {
			width: 80%;
			max-width: 500px;
			margin: 40px auto;
			padding: 80px;
			background: #FFFCF6;
			border: 1px solid #eee;
			box-shadow: 0 10px 6px -6px #777;
		}
		ul {
			border-top: 1px dotted #ccc;
			padding: 10px 0 0 0;
			-webkit-padding-start: 0;
		}
		li {
			padding-top: 10px;
		}
		a,
		a:visited {
			text-decoration: none;
			color: #6295b5;
		}
		a:active,
		a:hover {
			color: #7792a2;
		}
		p {
			text-indent: 1em;
		}
	</style>
</body>
</html>`