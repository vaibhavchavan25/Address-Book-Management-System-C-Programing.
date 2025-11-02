🧩 How to Compile and Run the Project
1. Prerequisites

Make sure you have the following installed on your system:

GCC Compiler

Any text editor or IDE (VS Code, Code::Blocks, Dev C++, etc.)

2. Clone or Download

Clone the repository using:

git clone https://github.com/Nakulvadar/Address-Book-Management-System-C-Programming.git


Or download the ZIP file and extract it.

3. Navigate to the Project Directory
cd Address-Book-Management-System-C-Programming

4. Compile the Code

Use GCC to compile the source file:

gcc address_book.c -o address_book


(If your project has multiple .c files, compile them together, for example:)

gcc main.c contact.c menu.c -o address_book

5. Run the Executable
./address_book


(For Windows users)

address_book.exe

6. Usage

Once the program starts:

Choose options from the menu to add, search, edit, delete, or view contacts.

All records are stored in a file for data persistence.
