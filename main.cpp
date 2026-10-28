
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string course;
    double marks;
};

const string FILE_NAME = "students.txt";

int readInt(const string& prompt) {
    int value;

    while (true) {
        cout << prompt;

        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << "Invalid input. Please enter a whole number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double readMarks() {
    double marks;

    while (true) {
        cout << "Enter marks (0-100): ";

        if (cin >> marks && marks >= 0 && marks <= 100) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return marks;
        }

        cout << "Invalid marks. Enter a value from 0 to 100.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string readText(const string& prompt) {
    string value;

    while (true) {
        cout << prompt;
        getline(cin, value);

        if (value.find_first_not_of(" \t\r\n") != string::npos) {
            return value;
        }

        cout << "Input cannot be empty. Please try again.\n";
    }
}

int findStudent(const vector<Student>& students, int id) {
    for (int i = 0; i < static_cast<int>(students.size()); i++) {
        if (students[i].id == id) {
            return i;
        }
    }

    return -1;
}

void loadStudents(vector<Student>& students) {
    ifstream file(FILE_NAME);
    Student student;

    while (file >> student.id
                >> quoted(student.name)
                >> student.age
                >> quoted(student.course)
                >> student.marks) {
        students.push_back(student);
    }
}

void saveStudents(const vector<Student>& students) {
    ofstream file(FILE_NAME);

    if (!file) {
        cout << "Error: Could not save student records.\n";
        return;
    }

    for (const Student& student : students) {
        file << student.id << ' '
             << quoted(student.name) << ' '
             << student.age << ' '
             << quoted(student.course) << ' '
             << student.marks << '\n';
    }
}

void addStudent(vector<Student>& students) {
    Student student;

    student.id = readInt("Enter student ID: ");

    if (findStudent(students, student.id) != -1) {
        cout << "That student ID already exists.\n";
        return;
    }

    student.name = readText("Enter student name: ");
    student.age = readInt("Enter age: ");

    if (student.age <= 0 || student.age > 120) {
        cout << "Invalid age. Student was not added.\n";
        return;
    }

    student.course = readText("Enter course: ");
    student.marks = readMarks();

    students.push_back(student);
    saveStudents(students);

    cout << "Student added successfully!\n";
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records found.\n";
        return;
    }

    cout << "\n"
         << left
         << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(10) << "Age"
         << setw(25) << "Course"
         << setw(10) << "Marks" << '\n';

    cout << string(80, '-') << '\n';

    for (const Student& student : students) {
        cout << left
             << setw(10) << student.id
             << setw(25) << student.name
             << setw(10) << student.age
             << setw(25) << student.course
             << fixed << setprecision(2)
             << setw(10) << student.marks << '\n';
    }
}

void searchStudent(const vector<Student>& students) {
    int id = readInt("Enter student ID to search: ");
    int index = findStudent(students, id);

    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    const Student& student = students[index];

    cout << "\nStudent found:\n"
         << "ID: " << student.id << '\n'
         << "Name: " << student.name << '\n'
         << "Age: " << student.age << '\n'
         << "Course: " << student.course << '\n'
         << "Marks: " << student.marks << '\n';
}

void updateStudent(vector<Student>& students) {
    int id = readInt("Enter student ID to update: ");
    int index = findStudent(students, id);

    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    Student updated = students[index];

    cout << "Enter the new details:\n";
    updated.name = readText("Enter student name: ");
    updated.age = readInt("Enter age: ");

    if (updated.age <= 0 || updated.age > 120) {
        cout << "Invalid age. Update cancelled.\n";
        return;
    }

    updated.course = readText("Enter course: ");
    updated.marks = readMarks();

    students[index] = updated;
    saveStudents(students);

    cout << "Student updated successfully!\n";
}

void deleteStudent(vector<Student>& students) {
    int id = readInt("Enter student ID to delete: ");
    int index = findStudent(students, id);

    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    students.erase(students.begin() + index);
    saveStudents(students);

    cout << "Student deleted successfully!\n";
}

int main() {
    vector<Student> students;
    loadStudents(students);

    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "0. Exit\n";

        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:
                addStudent(students);
                break;

            case 2:
                displayStudents(students);
                break;

            case 3:
                searchStudent(students);
                break;

            case 4:
                updateStudent(students);
                break;

            case 5:
                deleteStudent(students);
                break;

            case 0:
                cout << "Exiting Student Management System.\n";
                break;

            default:
                cout << "Invalid choice. Please select 0-5.\n";
        }

    } while (choice != 0);

    return 0;
}
