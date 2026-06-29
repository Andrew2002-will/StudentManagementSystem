#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;

Student::Student(int i, string n, int a) {
    id = i;
    name = n;
    age = a;
}

void Student::display() {
    cout << id << " " << name << " " << age << endl;
}

void Student::saveToFile() {
    ofstream file("students.txt", ios::app);

    if (file.is_open()) {
        file << id << " " << name << " " << age << endl;
        file.close();
    }
}

void Student::searchStudent(int searchId) {
    ifstream file("students.txt");

    int id, age;
    string name;
    bool found = false;

    while (file >> id >> name >> age) {
        if (id == searchId) {
            cout << "\nStudent Found:\n";
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;

            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "\nStudent not found!\n";
    }
}

void Student::displayAllStudents() {
    ifstream file("students.txt");

    int id, age;
    string name;

    cout << "\n===== All Students =====\n";

    while (file >> id >> name >> age) {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Age: " << age << endl;
    }

    file.close();
}

void Student::deleteStudent(int deleteId) {
    ifstream file("students.txt");
    ofstream temp("temp.txt");

    int id, age;
    string name;
    bool found = false;

    while (file >> id >> name >> age) {
        if (id != deleteId) {
            temp << id << " " << name << " " << age << endl;
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nStudent deleted successfully!\n";
    else
        cout << "\nStudent not found!\n";
}