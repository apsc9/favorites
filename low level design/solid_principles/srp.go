// Single responsibility principle : A class or module should have only one reason to change
// In other words, a type should have a single responsibility

type User struct {
	FirstName string
	LastName  string
}

func (u *User) GetName() string {
	return u.FirstName + " " + u.LastName
}

func (u *User) Save() error {
	// save user to db
}

// In the above case, the struct User has 2 responsibilities : getting user data and saving
// it to the database. To follow SRP, we need to separate these concerns

type User struct {
	FirstName string
	LastName  string
}

func (u *User) GetName() string {
	return u.FirstName + " " + u.LastName
}

type UserRepository struct {
	// db connection or other storage related fields
}

func (r *UserRepository) Save(u *User) error {
	// save user to db
}

// now the User struct is responsible only for maintaining user data
// while userRepo handles database operations

// example with logic :

type User struct {
	ID    int
	Name  string
	Email string
}

type UserRepository struct {
	db *sql.DB
}

func (repo *UserRepository) Save(user *User) error {
	query := "INSERT INTO users (id, name, email) VALUES ($1, $2, $3)"
	_, err := repo.db.Exec(query, user.ID, user.Name, user.Email)
	if err != nil {
		return fmt.Errorf("failed to save user: %w", err)
	}
	return nil
}

func main() {
	// simulated db connection
	db, _ := sql.Open("postgres", "your-dsn-string")
	defer db.Close()

	repo := &UserRepository{db: db}
	user := &User{ID: 1, Name: "Abc", Email: "abc@def.com"}

	if err := repo.Save(user); err != nil {
		fmt.Println("Error:", err)
	} else {
		fmt.Println("User saved successfully")
	}
}

// In simple words , (repo *UserRepository) ties the method to the UserRepository type, and
// user *User passes the data needed to perform the save operation.
// this separation of concerns and use of pointers ensures clean, efficient and maintainable code

