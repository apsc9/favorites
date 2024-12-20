// Go emphasizes composition by embedding one struct within another or using interfaces.
// A way to reuse code by assembling objects using smaller, reusable components
// (favoring "has-a" relationships).
package main

import "fmt"

type Swimmer interface {
	Swim() string
}

type Runner interface {
	Run() string
}

type Athlete struct {
	Name string
}

type Triathlete struct {
	Athlete
	Swimmer
	Runner
}

type Person struct{}

func (p Person) Swim() string {
	return "Swim fast"
}

func (p Person) Run() string {
	return "Run fast"
}

func main() {
	triathlete := Triathlete{
		Athlete: Athlete{Name: "abcd"},
		Swimmer: Person{},
		Runner:  Person{},
	}

	fmt.Println(triathlete.Name)
	fmt.Println(triathlete.Swim()) // from Person
	fmt.Println(triathlete.Run())  // from Person
}
