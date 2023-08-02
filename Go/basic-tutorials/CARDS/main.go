package main

import "fmt"

func main() {
	jumble()
	// read()
	// write()
	// util()
}

func jumble()  {
	cards := newDeck()
	fmt.Println("-----------Before shuffling-----------")
	cards.print()
	cards.shuffle()
	fmt.Println("-----------After shuffling-----------")
	cards.print()
}

func read() {
	cards := newDeckFromFile("my_cards")
	cards.print()
}

func write()  {
	cards := newDeck()
	cards.saveToFile("my_cards")
}

func util() {
	cards := newDeck()
	hand, remainingCards :=  deal(cards, 5) 
	hand.print()
	remainingCards.print()
}
