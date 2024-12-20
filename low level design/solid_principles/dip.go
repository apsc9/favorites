// Dependency Inversion Principle : dip states that high-level modules should not depend on low-level modules,
// but both should depend on abstractions. The principle promotes loose coupling between components, making the code
// more maintainable and testable

// consider an example where notifn service depends on email service for sending notifns

type EmailService struct{}

func (e *EmailService) Send(to string, message string) {
	// send email
}

type NotificationService struct {
	emailService *EmailService
}

func (n *NotificationService) Notify(to string, message string) {
	n.emailService.Send(to, message)
}

// in the above case notification service directly depends on the EmailService, making it difficult to
// switch to another notification method (SMS) or test the notifn in isolation. To follow the DIP,
// we can introduce an interface and depend on that instead:

// this is the abstraction(interface)
type MessageSender interface {
	Send(to string, message string)
}

// these are the low level modules (implementation details)
type EmailService struct{}
type SmSService struct{}

func (e *EmailService) Send(to string, message string) {
	// send email
}

func (s *SmSService) Send(to string, message string) {
	// send SMS
}

// this is the high level module
type NotificationService struct {
	messageSender MessageSender // depends on abstraction, not concrete implementation
}

func (n *NotificationService) Notify(to string, message string) {
	n.messageSender.Send(to, message)
}

// Adding new types of message senders is easy without modifying existing code:

type PushNotificationService struct{}

func (p *PushNotificationService) Send(to string, message string) {
	// Send push notification
}

// You can easily swap implementations without changing NotificationService

func main() {
	// Using email
	emailNotifier := &NotificationService{
		messageSender: &EmailService{},
	}

	emailNotifier.Notify("abc@xyz.com", "Aur bhai kaise ho?")

	// Using SMS
	smsNotifier := &NotificationService{
		messageSender: &SmSService{},
	}

	smsNotifier.Notify("9876543210", "Hello")

	pushNotifier := &NotificationService{
		messageSender: &PushNotificationService{},
	}

	pushNotifier.Notify("9988776655", "hello")
}