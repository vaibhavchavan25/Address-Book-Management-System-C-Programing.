# Address Book

Project Overview

The Address Book Management System is a C language application designed to efficiently manage personal contact information.
It allows users to add, search, edit, delete, and display contacts through a simple menu-driven interface.

The project demonstrates practical use of structures, file handling, and input validation (including email verification) to ensure data reliability and persistence.
All contact details are securely stored in a file, allowing data to remain available even after the program is closed.

## Features
- Add new contacts
- Display all contacts
- Search contacts by name or email
- Save and load contacts from a file
- Prevent duplicate emails

## How to Run
1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
2. Navigate to the project folder:
   ```bash
   cd AddressBook
   ```
3. Compile the project:
   ```bash
   gcc main.c contact.c file.c -o AddressBook
   ```
4. Run the program:
   ```bash
   ./AddressBook
   ```

## File Structure
```
AddressBook/
├── main.c          # Main program
├── contact.h       # Contact structure and function declarations
├── contact.c       # Contact management functions
├── file.h          # File handling declarations
├── file.c          # File handling implementations
└── README.md       # Project documentation
```

## Author
**Vaibhav Chavan**  
Electronic and Telecommunications Enthusiast

