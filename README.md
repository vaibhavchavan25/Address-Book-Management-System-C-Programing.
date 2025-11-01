# Address Book Management System (C Programming)

A C-based Address Book management system that demonstrates the use of structures, pointers, and file I/O.  
Designed for beginners in embedded and systems programming to practice memory management and data organization.
---

## Table of Contents
- [Features](#features)
- [Concepts Used](#concepts-used)
- [How to Compile and Run](#how-to-compile-and-run)
- [File Structure](#file-structure)
- [Sample Output](#sample-output)
- [Author](#author)

---

## Features

- Add new contacts (name, phone number, email, etc.)
- View all saved contacts
- Search for a contact by name or phone number
- Edit existing contact details
- Delete a contact
- File-based data storage (contacts remain saved after program exits)

---

## Concepts Used

- Structures (`struct`)
- File handling (`fopen`, `fread`, `fwrite`, `fprintf`, `fscanf`)
- Pointers and dynamic memory (optional)
- Functions and modular code organization
- Menu-driven interface

---

## How to Compile and Run

2. Navigate to the Project Folder
cd AddressBook

3. Compile and Run on Linux / macOS
gcc address_book.c -o address_book
./address_book

4. Compile and Run on Windows (MinGW)
gcc address_book.c -o address_book.exe
address_book.exe

File Structure
AddressBook/
├── address_book.c        # Main source code
├── contacts.txt          # Data file for storing contacts
└── README.md             # Project documentation

Sample Output
========== ADDRESS BOOK ==========
1. Add Contact
2. View Contacts
3. Search Contact
4. Edit Contact
5. Delete Contact
6. Exit
Enter your choice: 1

Enter Name: Vaibhav
Enter Email: vaibhav@example.com
Contact saved successfully!
