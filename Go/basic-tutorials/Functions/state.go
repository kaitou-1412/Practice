package main

import "fmt"

func printState()  {
	fmt.Println("Calcutta")

	cards := []string{"hi", "there", "you"}
	for index, card := range cards {
		fmt.Println(index, card)
	}
}