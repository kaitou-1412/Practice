package main

import "fmt"

type contactInfo struct {
	email string
	zipCode int
}

type person struct {
	firstName string
	lastName string
	age int
	isMarried bool
	contactInfo
}

func main() {
	// alex := person{"Alex", "Anderson"}
	alex := person{firstName: "Alex", lastName: "Anderson"}
	fmt.Println(alex)
	
	var michael person
	michael.firstName = "Michael"
	michael.lastName = "Jackson"
	fmt.Println(michael)
	michael.print()
	
	jim := person{
		firstName: "Jim",
		lastName: "Party",
		contactInfo: contactInfo{
			email: "jim@gmail.com",
			zipCode: 94000,
		},
	}
	fmt.Println(jim)
	jim.print()
	
	// jimPointer := &jim
	// jimPointer.updateName("Ruban")
	jim.updateName("Ruban")
	jim.print()
}

func (pointerToPerson *person) updateName(newFirstName string) {
	(*pointerToPerson).firstName = newFirstName	
}

func (p person) print() {
	fmt.Printf("%+v\n", p)  
}