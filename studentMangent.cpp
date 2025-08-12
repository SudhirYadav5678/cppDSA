#include <iostream>
#include <fstream>
using namespace std;

bool fileExists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

struct student {
    int id;
    string name;
    string address;
    string phone;
    int age;
};

class StudentManager {
public:
    void addStudent(student& s) {
        string filename = "student.txt";
        ofstream file(filename, ios::app); // append mode

        if (file.is_open()) {
            file << s.id << " "
                 << s.name << " "
                 << s.address << " "
                 << s.phone << " "
                 << s.age << "\n";
            file.close();
            cout << "Student added successfully.\n";
        } else {
            cerr << "Error while writing data to file.\n";
        }
    }

    void removeStudent(int id) {
        string filename = "student.txt";

        if (!fileExists(filename)) {
            cerr << "Error: File does not exist.\n";
            return;
        }

        ifstream inFile(filename);
        ofstream tempFile("temp.txt");

        student s;
        bool found = false;

        while (inFile >> s.id >> s.name >> s.address >> s.phone >> s.age) {
            if (s.id != id) {
                tempFile << s.id << " " << s.name << " " << s.address << " "
                         << s.phone << " " << s.age << "\n";
            } else {
                found = true;
            }
        }

        inFile.close();
        tempFile.close();

        remove("student.txt");
        rename("temp.txt", "student.txt");

        if (found) {
            cout << "Student with ID " << id << " removed successfully.\n";
        } else {
            cout << "Student with ID " << id << " not found.\n";
        }
    }

    void displayStudents() {
        string filename = "student.txt";
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Could not open the file.\n";
            return;
        }

        student s;
        cout << "\n--- Student Records ---\n";
        bool anyStudent = false;

        while (file >> s.id >> s.name >> s.address >> s.phone >> s.age) {
            cout << "ID: " << s.id << "\n";
            cout << "Name: " << s.name << "\n";
            cout << "Address: " << s.address << "\n";
            cout << "Phone: " << s.phone << "\n";
            cout << "Age: " << s.age << "\n";
            cout << "--------------------------\n";
            anyStudent = true;
        }

        if (!anyStudent) {
            cout << "No student records found.\n";
        }

        file.close();
    }
};

int main() {
    StudentManager manager;
    student s;
    int choice;

    do {
        cout << "\nStudent Manager\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Display Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter ID: "; cin >> s.id;
            cout << "Enter Name: "; cin >> s.name;
            cout << "Enter Address: "; cin >> s.address;
            cout << "Enter Phone: "; cin >> s.phone;
            cout << "Enter Age: "; cin >> s.age;
            manager.addStudent(s);
            break;
        case 2:
            int id;
            cout << "Enter ID to remove: ";
            cin >> id;
            manager.removeStudent(id);
            break;
        case 3:
            manager.displayStudents();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
