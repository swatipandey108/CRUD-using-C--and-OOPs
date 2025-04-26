#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Class representing a single student record
class Record {
public:
    string id;
    string name;
    string grade;

    Record(const string& id, const string& name, const string& grade)
        : id(id), name(name), grade(grade) {}
};

// Class to manage student records
class RecordManager {
private:
    vector<Record> records; // Stores all records

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
        cin >> name;
        cout << "Enter Grade: ";
        cin >> grade;

        // Check if ID already exists
        if (findRecordById(id) != records.end()) {
            cout << "\n⚠️ Record with ID " << id << " already exists. Insertion cancelled.\n";
            return;
        }

        records.emplace_back(id, name, grade);
        cout << "\n✅ Record inserted successfully!\n";
    }

    // Function to delete a record by ID
    void deleteRecord() {
        string id;
        cout << "\nEnter ID to delete: ";
        cin >> id;

        auto it = findRecordById(id);
        if (it != records.end()) {
            records.erase(it);
            cout << "\n✅ Record deleted successfully!\n";
        } else {
            cout << "\n⚠️ No record found with ID " << id << ".\n";
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
            it->grade = newGrade;
            cout << "\n✅ Grade updated successfully!\n";
        } else {
            cout << "\n⚠️ No record found with ID " << id << ".\n";
        }
    }

    // Function to display all records
    void displayRecords() const {
        cout << "\n📋 All Student Records:\n";

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
};

void displayMenu() {
    cout << "\n=== Student Record Management ===\n";
    cout << "1. Insert Record\n";
    cout << "2. Delete Record\n";
    cout << "3. Update Record\n";
    cout << "4. Display All Records\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    RecordManager manager;
    int choice;
    bool running = true;

    while (running) {
        displayMenu();
        cin >> choice;

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
            case 0:
                cout << "\n👋 Exiting program. Goodbye!\n";
                running = false;
                break;
            default:
                cout << "\n❌ Invalid choice. Please enter a valid option (0-4).\n";
                break;
        }
    }

    return 0;
}
