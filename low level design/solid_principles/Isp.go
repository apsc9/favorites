// interface segregation principle : clients should not be forced to depend on interfaces they dont use.
// this encourages creating smaller, more focused interfaces rather than large, monolithic ones

type Document interface {
	Read() string
	Write(content string)
	Print() string
}

type TextDocument struct {
	content string
}

func (d *TextDocument) Read() string {
	return d.content
}

func (d *TextDocument) Write (content string) {
	d.content = content
}

func (d *TextDocument) Print() string {
	return "Printing: " + d.content
}

// if we have a ReadOnlyDocument, the current implementation forces us to implement unnecessary methods

type ReadOnlyDocument struct {
	content string
}

func (d *ReadOnlyDocument) Read() string {
	return d.content
}

func (d *ReadOnlyDocument) Write (content string) {
	// not supported
}

funct (d *ReadOnlyDocument) Print() string {
	// not supported
}




// In order to follow ISP, we need to break the interface into smaller, more focused interfaces
// Here is the refactored code which follows Interface segregation principle

type Reader interface {
	Read() string
}

type Writer interface {
	Write(content string)
}

type Printer interface {
	Print() string
}

type TextDocument struct {
	content string
}

// implement Reader writer and Printer interface for TextDocument

type ReadOnlyDocument struct {
	content string 
}

// implement Reader interface only for this one 
func (d *ReadOnlyDocument) Read() string {
	return d.content
}