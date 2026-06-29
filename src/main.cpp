#include <iostream>
#include "Student.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, age;
            string name;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Age: ";
            cin >> age;

            Student s(id, name, age);
            s.saveToFile();

            cout << "\nStudent Added Successfully!\n";
            s.display();
        }

        else if (choice == 2) {
            Student s(0, "", 0);
            s.displayAllStudents();
        }

        else if (choice == 3) {
            int searchId;

            cout << "Enter ID to search: ";
            cin >> searchId;

            Student s(0, "", 0);
            s.searchStudent(searchId);
        }

        else if (choice == 4) {
            int deleteId;

            cout << "Enter ID to delete: ";
            cin >> deleteId;

            Student s(0, "", 0);
            s.deleteStudent(deleteId);
        }

    } while (choice != 0);

    cout << "Exiting program...\n";
    return 0;
}