// Polymorphism in Go is achieved using interfaces, which allow different types
// to be treated uniformly as long as they implement the same interface.
// Dog and Cat inplement the Animal interface by defining the Speak Method
// Talk function can accept any type that satisfies the Animal interface

package main

import "fmt"

type Animal interface {
	Speak() string
}

// struct implemen an interface
type Dog struct{}

func (d Dog) Speak() string {
	return "Woof!"
}

// another struct implement an interface
type Cat struct{}

func (c Cat) Speak() string {
	return "Meow!"
}

func Talk(a Animal) {
	fmt.Println(a.Speak())
}

func main() {
	c := Cat{}
	d := Dog{}

	Talk(c)
	Talk(d)

}
