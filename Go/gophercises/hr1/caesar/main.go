package main

import (
	"fmt"
)

func main() {
	fmt.Println("Cipher Problem: https://www.hackerrank.com/challenges/caesar-cipher-1/problem")
}

func caesarCipher(s string, k int32) string {
    // Write your code here
    var ans []rune
    for _, r := range s {
        var base rune
        if 'A' <= r && r <= 'Z' {
            base = 'A'
        } else if 'a' <= r && r <= 'z' {
            base = 'a'
        } else {
            ans = append(ans, r)
            continue
        }
        temp := int32(r) - int32(base)
        temp = (temp + k) % 26
        r = rune(temp + base)
        ans = append(ans, r)
    }
    return string(ans)
}