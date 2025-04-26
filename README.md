📚 Student Record Management System (C++ OOP)
A simple Student Record Management System developed using C++ and Object-Oriented Programming (OOP) principles.
This project operates entirely in-memory using vectors — no databases or external file handling required.

✨ Features
➕ Insert a new student record

🗑️ Delete a student record by ID

✏️ Update a student's grade

📋 Display all student records

🚫 No external database or file storage

🔥 Lightweight and fast (perfect for beginners)

🛠 Technologies Used
C++ (Standard Template Library)

OOP Concepts (Classes, Encapsulation)

Vectors for dynamic storage

Lambda functions for search functionality

📂 Project Structure
plaintext
Copy
Edit
.
├── main.cpp     # Source code of the project
└── README.md    # Project documentation (this file)
📋 Menu Options
plaintext
Copy
Edit
=== Student Record Management ===
1. Insert Record
2. Delete Record
3. Update Record
4. Display All Records
0. Exit
🚀 How to Run
Clone or download this repository.

Compile the code using a C++ compiler. Example:

bash
Copy
Edit
g++ main.cpp -o student_records
./student_records
Interact with the menu-driven interface to manage student records.

🧩 How It Works
Record Class: Represents a student (ID, Name, Grade).

RecordManager Class: Manages operations like insert, delete, update, and display.

Vector is used to store all the student records dynamically.

Lambda function is used inside std::find_if for efficiently finding records by ID.

📑 Example
plaintext
Copy
Edit
Enter your choice: 1
Enter ID: 101
Enter Name: Alice Johnson
Enter Grade: A

✅ Record inserted successfully!

Enter your choice: 4

📋 All Student Records:
----------------------------------
ID      Name    Grade
----------------------------------
101     Alice Johnson    A
----------------------------------
💡 Possible Improvements
Add saving and loading from a file for data persistence.

Add input validation (e.g., numeric IDs only).

Implement search functionality by name.

Provide sorting options (e.g., sort by Name or Grade).

Build a GUI version using frameworks like Qt or SFML.

📜 License
This project is open-source and free for educational or personal use.

🙌 Acknowledgment
Made with ❤️ to practice C++ fundamentals and OOP concepts.

