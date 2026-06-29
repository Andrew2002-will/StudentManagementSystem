#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    int id;
    std::string name;
    int age;

public:
    Student(int i, std::string n, int a);
    void display();
    void saveToFile();
    void searchStudent(int searchId);
    void displayAllStudents();
    void deleteStudent(int deleteId);
};

#endif