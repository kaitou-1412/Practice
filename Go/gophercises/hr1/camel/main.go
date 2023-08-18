package main

import (
	"fmt"
	"unicode"
)

func main() {
	fmt.Println("Camel Problem: https://www.hackerrank.com/challenges/camelcase/problem")
}

func camelcase(s string) int32 {
    // Write your code here
    var ans int32 = 1
    for _, r := range s {
        if unicode.IsUpper(r) {
            ans++
        }
    }
    return ans
}