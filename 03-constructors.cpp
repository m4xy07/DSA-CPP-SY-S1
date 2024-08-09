#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    Student(string name, int rollNumber, string email) {
        this->name = name;
        this->rollNumber = rollNumber;
        this->email = email;
    }

    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Email: " << email << endl;
    }

private:
    string name;
    int rollNumber;
    string email;
};


int main() {
    string name, email;
    int rollNumber;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter roll number: ";
    cin >> rollNumber;

    cin.ignore();

    cout << "Enter email: ";
    getline(cin, email);

    Student student(name, rollNumber, email);
    student.displayInfo();

    return 0;
}