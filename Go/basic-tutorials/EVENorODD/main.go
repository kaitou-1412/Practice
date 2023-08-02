package main

import "fmt"

func main() {
	nums := []int{}
	for i := 0; i <= 10; i++ {
		nums = append(nums, i)
	}
	
	for index, num := range nums {
		if num % 2 == 0 {
			fmt.Println(index, " is even")
		} else {
			fmt.Println(index, " is odd" )
		}
	}
}