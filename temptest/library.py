import datetime

class User:
    def __init__(self, user_id, name):
        self.user_id = user_id
        self.name = name

class Book:
    def __init__(self, title, author, available_copies, category):
        self.title = title
        self.author = author
        self.available_copies = available_copies
        self.total_copies = available_copies
        self.category = category

class Loan:
    def __init__(self, user, book):
        self.user = user
        self.book = book
        self.borrow_date = datetime.date.today()
        self.returned = False

class Library:
    def __init__(self):
        self.users = []
        self.books = []
        self.loans = []

    def add_user(self, user):
        self.users.append(user)
        print(f"User '{user.name}' added to the library.")

    def add_book(self, book):
        self.books.append(book)
        print(f"Book '{book.title}' by {book.author} added to the library.")

    def borrow_book(self, user_id, title):
        user = next((u for u in self.users if u.user_id == user_id), None)
        if user:
            book = next((b for b in self.books if b.title == title), None)
            if book:
                if book.available_copies > 0:
                    book.available_copies -= 1
                    print(f"Book '{book.title}' by {book.author} borrowed successfully by {user.name}.")
                else:
                    print(f"Error: No available copies of '{book.title}' by {book.author}.")
            else:
                print(f"Error: Book '{title}' not found in the library.")
        else:
            print(f"Error: User with ID {user_id} not found.")

    def return_book(self, user_id, title):
        user = next((u for u in self.users if u.user_id == user_id), None)
        if user:
            book = next((b for b in self.books if b.title == title), None)
            if book:
                loan = next((l for l in self.loans if l.user == user and l.book == book and not l.returned), None)
                if loan:
                    book.available_copies += 1
                    print(f"Book '{book.title}' by {book.author} returned successfully by {user.name}.")
                else:
                    print(f"Error: {user.name} did not borrow '{book.title}' by {book.author}.")
            else:
                print(f"Error: Book '{title}' not found in the library.")
        else:
            print(f"Error: User with ID {user_id} not found.")
