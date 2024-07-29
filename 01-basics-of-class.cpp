#include <iostream>
using namespace std;

class Student
{
    public:
        string name;
        int age;
        int roll_no;
        void print()
        {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Roll No: " << roll_no << endl;
        }
};

int main()
{
    Student s1;
    cout << "Enter the name, age and roll no of the student: ";
    cin >> s1.name >> s1.age >> s1.roll_no;
    s1.print();
    return 0;
}