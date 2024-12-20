// Encapsulation is a fundamental concept in object-oriented programming (OOP) that involves bundling data (attributes) and the methods (functions) that operate on that data into a single unit, typically a class. This practice not only organizes code but also restricts direct access to some of an object's components, thereby protecting the integrity of the data and preventing unintended interference.

package main

import "fmt"

type Person struct {
	name string // private field
	age  int    // private field
}

// constructor function to create new Person Instances
func NewPerson(name string, age int) *Person {
	return &Person{name: name, age: age}
}

// getter function for the name
func (p *Person) GetName() string {
	return p.name
}

// setter fn for the name
func (p *Person) SetName(name string) {
	p.name = name
}

// getter fn for age
func (p *Person) GetAge() int {
	return p.age
}

// setter function for age
func (p *Person) SetAge(age int) {
	if age > 0 {
		p.age = age
	}

}

func main() {
	person := NewPerson("abcd", 24)

	fmt.Println("Name:", person.GetName())
	fmt.Println("Age:", person.GetAge())

	person.SetName("def")
	person.SetAge(25)

	fmt.Println("Name:", person.GetName())
	fmt.Println("Name:", person.GetAge())
}
