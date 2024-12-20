// go doesnt officially support inheritance, however this can be demonstrated through composition
// inheritance extends the functionality of base types in an "is-a" relationship

package main

import "fmt"

type Animal struct {
	Name string
}

func (a Animal) Speak() string {
	return "Woof Woof"
}

type Dog struct {
	Animal // embedding
}

func (d Dog) Speak() string {
	return "Aur bhai aa gya smajh?"
}

func main() {
	d := Dog{
		Animal: Animal{Name: "Rick"}}

	fmt.Println(d.Name)
	fmt.Println(d.Speak())
}
