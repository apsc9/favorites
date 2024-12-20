// liskov's substitution principle: lsp states that objects of a superclass should be replaceable with objects
// of its subclasses without breaking the application. In Go terms, this means that if an interface promises certain
// behaviour, all types that implement that interface should fulfill those behavioral promises without breaking the
// functionality using the interface

// example violating the LSP :

type Bird interface {
	Fly() string
}

type Pigeon struct{}

func (p *Pigeon) Fly() string {
	return "Pigeon is flying"
}

type Penguin struct{}

func (p *Penguin) Fly() string {
	return "Penguin is flying"
}

// but penguins cant fly,
// so penguin implementation breaks LSP

// Here is the refactored code:

type Bird interface {
	MakeSound() string
}

type FlyingBird interface {
	Bird
	Fly() string
}

type Pigeon struct{}

func (p *Pigeon) MakeSound() string {
	return "Coo"
}

func (p *Pigeon) Fly() string {
	return "Pigeon is flying"
}

type Penguin struct{}

func (p *Penguin) MakeSound() string {
	return "Squawk"
}

func MakeBirdSound(b Bird) string {
	return b.MakeSound()
}

func main() {
	pigeon := &Pigeon{}
	penguin := &Penguin{}

	// Both work fine because both implement Bird
	MakeBirdSound(pigeon)  // Works
	MakeBirdSound(penguin) // Works
}