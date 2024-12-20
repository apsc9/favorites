// Abstraction in Go is achieved by defining interfaces. Interfaces allow you to
// specify behavior without exposing implementation details.

// Circle and Rectangle types implement the Shape interface by defining the Area method.
// The PrintArea function abstracts the behavior of calculating the area,
// regardless of the specific shape.

package main

import "fmt"

// defininig interface
type Shape interface {
	Area() float64
}

// implementing interface for a circle
type Circle struct {
	Radius float64
}

func (c Circle) Area() float64 {
	return 3.14 * c.Radius * c.Radius
}

// implementing interface for a rect
type Rectangle struct {
	Width, Height float64
}

func (r Rectangle) Area() float64 {
	return r.Width * r.Height
}

// func that works with any Shape
func GetArea(s Shape) {
	fmt.Println(s.Area())
}

func main() {
	c := Circle{Radius: 5}
	r := Rectangle{Width: 4, Height: 5}
	GetArea(c)
	GetArea(r)
}
