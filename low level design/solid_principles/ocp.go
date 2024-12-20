// Open/Closed Principle : it states that the software entities(classes, modules, fns) should be 
// open for extension but closed for modification. This ensures that the code can be extended without the need
// for significant modifications

// say we have a fn to calc the area of a rect

type Rectangle struct {
	Width float64
	Height float64
}

func Area(rect *Rectangle) float64 {
	return rect.Width * rect.Height
}

// now if we need to calc the area of a circle, the current implmntn requires modification

type Circle struct {
	Radius float64
}

func Area(shape Interface{}) float64 {
	switch s := shape.(type) {
	case *Rectangle:
		return s.Width * s.Height
	case *Circle:
		return math.Pi * math.Pow(s.Radius, 2)
	default:
		return 0
	}
}

// to follow ocp, we define an interface with area method and implement it for each shape

type Shape interface {
	Area() float64
}

func (r *Rectangle) Area () float64 {
	return r.Width * r.Height
}

func (c *Circle) Area () float64 {
	return math.Pi * math.Pow(c.Radius, 2)
}

// now the code is open for extension (we can add new shapes) but closed for 
// modification ( we dont need to change the area function)