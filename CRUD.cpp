#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Class representing a single student record
class Record {
public:
    string id;     // Student ID
    string name;   // Student Name
    string grade;  // Student Grade

    // Constructor to initialize a Record
    Record(const string& id, const string& name, const string& grade)
        : id(id), name(name), grade(grade) {}
};

// Class to manage student records
class RecordManager {
private:
    vector<Record> records; // Vector to store all student records

    // Helper function to find a record by ID
    vector<Record>::iterator findRecordById(const string& id) {
        return std::find_if(records.begin(), records.end(),
            [&id](const Record& rec) { return rec.id == id; });
    }

public:
    // Function to insert a new record
    void insertRecord() {
        string id, name, grade;

        cout << "\nEnter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, name); // Allow full name with spaces
        cout << "Enter Grade: ";
        cin >> grade;

        // Check if ID already exists
        if (findRecordById(id) != records.end()) {
            cout << "\nRecord with ID " << id << " already exists. Insertion cancelled.\n";
            return;
        }

        // Add the new record
        records.emplace_back(id, name, grade);
        cout << "\nRecord inserted successfully!\n";
    }

    // Function to delete a record by ID
    void deleteRecord() {
        string id;
        cout << "\nEnter ID to delete: ";
        cin >> id;

        auto it = findRecordById(id);
        if (it != records.end()) {
            records.erase(it);  // Remove the record
            cout << "\nRecord deleted successfully!\n";
        } else {
            cout << "\nNo record found with ID " << id << ".\n";
        }
    }

    // Function to update the grade of an existing record
    void updateRecord() {
        string id, newGrade;
        cout << "\nEnter ID to update: ";
        cin >> id;

        auto it = findRecordById(id);
        if (it != records.end()) {
            cout << "Enter new Grade: ";
            cin >> newGrade;
            it->grade = newGrade;  // Update the grade
            cout << "\nGrade updated successfully!\n";
        } else {
            cout << "\nNo record found with ID " << id << ".\n";
        }
    }

    // Function to display all records
    void displayRecords() const {
        cout << "\nAll Student Records:\n";

        if (records.empty()) {
            cout << "No records available.\n";
            return;
        }

        cout << "----------------------------------\n";
        cout << "ID\tName\tGrade\n";
        cout << "----------------------------------\n";

        for (const auto& rec : records) {
            cout << rec.id << "\t" << rec.name << "\t" << rec.grade << "\n";
        }

        cout << "----------------------------------\n";
    }

    // Function to search a record by ID
    void searchById() const {
        string id;
        cout << "\nEnter ID to search: ";
        cin >> id;

        auto it = std::find_if(records.begin(), records.end(),
            [&id](const Record& rec) { return rec.id == id; });

        if (it != records.end()) {
            cout << "\nRecord Found:\n";
            cout << "ID: " << it->id << "\nName: " << it->name << "\nGrade: " << it->grade << "\n";
        } else {
            cout << "\nNo record found with ID " << id << ".\n";
        }
    }

    // Function to search records by Name (partial match)
    void searchByName() const {
        string namePart;
        cout << "\nEnter part of the Name to search: ";
        cin.ignore(); // Clear input buffer
        getline(cin, namePart);

        bool found = false;
        cout << "\nSearch Results:\n";

        for (const auto& rec : records) {
            if (rec.name.find(namePart) != string::npos) {
                cout << "ID: " << rec.id << " | Name: " << rec.name << " | Grade: " << rec.grade << "\n";
                found = true;
            }
        }

        if (!found) {
            cout << "No matching records found.\n";
        }
    }

    // Function to display all records sorted by Name
    void displaySortedByName() const {
        if (records.empty()) {
            cout << "\nNo records available to sort.\n";
            return;
        }

        // Copy records to a temporary vector
        vector<Record> sortedRecords = records;

        // Sort based on name
        sort(sortedRecords.begin(), sortedRecords.end(),
             [](const Record& a, const Record& b) {
                 return a.name < b.name;
             });

        cout << "\nRecords Sorted by Name:\n";
        cout << "----------------------------------\n";
        cout << "ID\tName\tGrade\n";
        cout << "----------------------------------\n";
        for (const auto& rec : sortedRecords) {
            cout << rec.id << "\t" << rec.name << "\t" << rec.grade << "\n";
        }
        cout << "----------------------------------\n";
    }
};

// Function to display the main menu
void displayMenu() {
    cout << "\n=== Student Record Management ===\n";
    cout << "1. Insert Record\n";
    cout << "2. Delete Record\n";
    cout << "3. Update Record\n";
    cout << "4. Display All Records\n";
    cout << "5. Search Record by ID\n";
    cout << "6. Search Record by Name\n";
    cout << "7. Display Records Sorted by Name\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    RecordManager manager;
    int choice;
    bool running = true;

    // Main loop
    while (running) {
        displayMenu(); // Show menu options
        cin >> choice; // Get user choice

        // Handle the choice
        switch (choice) {
            case 1:
                manager.insertRecord();
                break;
            case 2:
                manager.deleteRecord();
                break;
            case 3:
                manager.updateRecord();
                break;
            case 4:
                manager.displayRecords();
                break;
            case 5:
                manager.searchById();
                break;
            case 6:
                manager.searchByName();
                break;
            case 7:
                manager.displaySortedByName();
                break;
            case 0:
                cout << "\nExiting program. Goodbye!\n";
                running = false;
                break;
            default:
                cout << "\nInvalid choice. Please enter a valid option (0-7).\n";
                break;
        }
    }

    return 0;
}
