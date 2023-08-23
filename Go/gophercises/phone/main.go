package main

import (
	"fmt"
	"log"
	"os"
	phoneDB "phone/db"
	"regexp"
	"strconv"

	"github.com/joho/godotenv"
	_ "github.com/lib/pq"
)

func main() {
	host, port, dbname, username, password := getDatabaseDetails()
    psqlInfo := fmt.Sprintf("host=%s port=%d user=%s password=%s sslmode=disable", host, port, username, password)
	// must(phoneDB.Reset("postgres", psqlInfo, dbname)) 

	psqlInfo = fmt.Sprintf("%s dbname=%s", psqlInfo, dbname)
	// must(phoneDB.Migrate("postgres", psqlInfo))
	
	db, err := phoneDB.Open("postgres", psqlInfo)
	must(err)
	defer db.Close()

	// must(db.Seed())

	phones, err := db.AllPhones()
	must(err)
	for _, p := range phones {
		fmt.Printf("Working on... %+v\n", p)
		number := normalize(p.Number)
		if number != p.Number {
			fmt.Println("Updating or removing...", number)
			existing, err := db.FindPhone(number)
			must(err)
			if existing != nil {
				must(db.DeletePhone(p.ID))
			} else {
				p.Number = number
				must(db.UpdatePhone(p))
			}
		} else {
			fmt.Println("No changes required")
		}
	}
}

type phone struct {
	id     int
	number string
} 

func must(err error) {
	if err != nil {
		panic(err)
	}
}

func getDatabaseDetails() (string, int, string, string, string) {
	var envs map[string]string
    envs, err := godotenv.Read(".env")
    if err != nil {
        log.Fatal("Error loading .env file")
		os.Exit(1)
    }
	host := envs["DB_HOST"]
	port := getIntFromString(envs["DB_PORT"])
	dbname := envs["DB_NAME"]
    username := envs["DB_USERNAME"]
    password := envs["DB_PASSWORD"]
	return host, port, dbname, username, password
}

func getIntFromString(s string) int {
	num, err := strconv.Atoi(s)
	if err != nil {
		fmt.Println("Failed to convert the string:", s)
		os.Exit(1)
	}
	return num
}

// Regular Expressions 
func normalize(phone string) string {	
	// re := regexp.MustCompile("[^0-9]")
	re := regexp.MustCompile("\\D")
	return re.ReplaceAllString(phone, "")
}

// Iterating the string
// func normalize(phone string) string {
// 	var buf bytes.Buffer
// 	for _, r := range phone {
// 		if '0' <= r && r <= '9' {
// 			buf.WriteRune(r)
// 		}
// 	}
// 	return buf.String()
// }
