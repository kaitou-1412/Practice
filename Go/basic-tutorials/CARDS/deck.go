package main

import (
	"fmt"
	"io/ioutil"
	"math/rand"
	"os"
	"strings"
	"time"
)

// create a new type of 'deck'
// which is a slice of strings
type deck []string


// Reciever function

func newDeck() deck {
	// Create and return a list of playing cards
	cards := deck{} 
	cardSuites := []string{"Spades", "Hearts", "Diamonds", "Clubs"}
	cardValues := []string{"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"}
	for _, suit := range cardSuites {
		for _, value := range cardValues {
			cards = append(cards, value + " of " + suit)
		} 
	}
	return cards  
}

func (d deck) print()  {
	// Log out the contents of a deck of cards
	for i, card := range d {
		fmt.Println(i, card) 
	} 
}

func deal(d deck, handSize int) (deck, deck) {
	// Create a 'hand' of cards
	return d[:handSize], d[handSize:]
}

func (d deck) toString() string {
	// deck --> []string --> string
	return strings.Join([]string(d), ",") 
}

func (d deck) saveToFile(filename string) error {
	// Save a list of cards to a file on a local machine
	// string --> []byte
	return ioutil.WriteFile(filename, []byte(d.toString()), 0666)
}

func newDeckFromFile(filename string) deck {
	// Load a list of cards from the local machine
	// get byte-slice and error
	bs, err := ioutil.ReadFile(filename)
	if err != nil {
		fmt.Println("Error:", err)
		os.Exit(1)
	}
	
	// []byte --> string --> []string
	s := strings.Split(string(bs), ",")
	// []string --> deck
	return deck(s) 
}

func (d deck) shuffle() {
	// Shuffles all the cards in a deck
	for i := range d {
		newPosition := trulyRandomNumberGenerator(len(d))
		d[i], d[newPosition] = d[newPosition], d[i]
		 
	}
}

func trulyRandomNumberGenerator(num int ) int {
	source := rand.NewSource(time.Now().UnixNano())
	r := rand.New(source)
	return r.Intn(num)
}
