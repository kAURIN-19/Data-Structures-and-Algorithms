#include <iostream>
#include <vector>
#include <string>
#include <cctype>   
#include <algorithm> 
using namespace std;

struct Student {
    string studentID;       
    string lastName;       
    string firstName;        
    string sex;            
    string contactNo;      
    string address;         
};

vector<Student> students;

bool isDuplicateID(const string& id) {
    for (const auto& student : students) {
        if (student.studentID == id) {
            return true; 
        }
    }
    return false; 
}

bool isValidContactNo(const string& contactNo) {
    return contactNo.length() == 11 && all_of(contactNo.begin(), contactNo.end(), ::isdigit);
}

bool isValidSex(const string& sex) {
    return sex == "M" || sex == "m" || sex == "F" || sex == "f";
}

string toUpperCase(const string& str) {
    string upperStr = str;
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    return upperStr;
}

template<typename T>
void getInput(const string& prompt, T& value, bool (*validationFunc)(const T&) = nullptr) {
    while (true) {
        cout << prompt;
        getline(cin, value);
        if (validationFunc == nullptr || validationFunc(value)) {
            break; 
        }
        cout << "Error: Invalid input. Please try again.\n";
    }
}

bool isDuplicateContactNo(const string& contactNo) {
    for (const auto& student : students) {
        if (student.contactNo == contactNo) {
            return true; 
        }
    }
    return false; 
}

void insertRecord() {
    Student newStudent;

    cout << "\n--- Add New Student Record ---\n";
    
    getInput("Enter Student ID: ", newStudent.studentID);
    while (newStudent.studentID.empty() || isDuplicateID(newStudent.studentID)) {
        cout << "Error: Student ID already exists or is empty. Please enter a unique ID.\n";
        getInput("Enter Student ID: ", newStudent.studentID);
    }

    getInput("Enter Last Name: ", newStudent.lastName);
    while (newStudent.lastName.empty()) {
        cout << "Error: Last Name cannot be empty. Please enter again: ";
        getInput("", newStudent.lastName);
    }

    getInput("Enter First Name: ", newStudent.firstName);
    while (newStudent.firstName.empty()) {
        cout << "Error: First Name cannot be empty. Please enter again: ";
        getInput("", newStudent.firstName);
    }

    getInput("Enter Sex (M/F): ", newStudent.sex, isValidSex);

    getInput("Enter Contact Number: ", newStudent.contactNo, isValidContactNo);
    while (isDuplicateContactNo(newStudent.contactNo)) {
        cout << "Error: Contact Number already exists. Please enter a unique Contact Number: ";
        getInput("", newStudent.contactNo, isValidContactNo);
    }

    getInput("Enter Address: ", newStudent.address);
    while (newStudent.address.empty()) {
        cout << "Error: Address cannot be empty. Please enter again: ";
        getInput("", newStudent.address);
    }

    students.push_back(newStudent);
    cout << "\nStudent record added successfully!\n";
}

void displayRecords() {
    if (students.empty()) {
        cout << "\nNo student records available.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";
    for (size_t i = 0; i < students.size(); ++i) {
        cout << "\nRecord " << i + 1 << ":\n";
        cout << "Student ID: " << students[i].studentID << endl;
        cout << "Last Name: " << students[i].lastName << endl;
        cout << "First Name: " << students[i].firstName << endl;
        cout << "Sex: " << students[i].sex << endl;
        cout << "Contact Number: " << students[i].contactNo << endl; 
        cout << "Address: " << students[i].address << endl; 
    }
}

void updateRecord() {
    string studentID;
    cout << "\n--- Update Student Record ---\n";
    cout << "Enter Student ID to update: ";
    cin >> studentID;
    cin.ignore(); 

    studentID = toUpperCase(studentID);
    
    bool found = false;
    for (auto& student : students) {
        string storedID = toUpperCase(student.studentID);
        if (storedID == studentID) {
            found = true;

            getInput("Enter New Last Name: ", student.lastName);
            while (student.lastName.empty()) {
                cout << "Error: Last Name cannot be empty. Please enter again: ";
                getInput("", student.lastName);
            }

            getInput("Enter New First Name: ", student.firstName);
            while (student.firstName.empty()) {
                cout << "Error: First Name cannot be empty. Please enter again: ";
                getInput("", student.firstName);
            }

            getInput("Enter New Sex (M/F): ", student.sex, isValidSex);

            string newContactNo;
            getInput("Enter New Contact Number: ", newContactNo, isValidContactNo);

            // Check if the new contact number already exists for other students
            if (isDuplicateContactNo(newContactNo) && newContactNo != student.contactNo) {
                cout << "Error: Contact Number already exists. Please enter a unique Contact Number: ";
                continue; // Restart the input process
            }
            student.contactNo = newContactNo; // Update the contact number

            getInput("Enter New Address: ", student.address);
            while (student.address.empty()) {
                cout << "Error: Address cannot be empty. Please enter again: ";
                getInput("", student.address);
            }

            cout << "\nStudent record updated successfully!\n";
            break;
        }
    }
    if (!found) {
        cout << "\nStudent record not found.\n";
    }
}

void deleteRecord() {
    string studentID;
    cout << "\n--- Delete Student Record ---\n";
    cout << "Enter Student ID to delete: ";
    cin >> studentID;
    cin.ignore(); 

    studentID = toUpperCase(studentID);

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (toUpperCase(it->studentID) == studentID) {
            students.erase(it);
            cout << "\nStudent record deleted successfully!\n";
            return;
        }
    }
    cout << "\nStudent record not found.\n";
}

void displayMenu() {
    cout << "\n--- Student Information System ---\n";
    cout << "1. Insert Record\n";
    cout << "2. Display Records\n";
    cout << "3. Update Record\n";
    cout << "4. Delete Record\n";
    cout << "5. Exit\n";
}

int main() {
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                insertRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                updateRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
