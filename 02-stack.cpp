#include <iostream>
using namespace std;
class stack
{
public:
    int top = -1, arr[6];

public:
    int value;
    void push()
    {
        if (top == 5)
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            cout << "Enter the value to be pushed: ";
            cin >> value;
            top++;
            arr[top] = value;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Popped value: " << arr[top] << endl;
            top--;
        }
    }
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack: ";
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    stack s;
    int choice;
    while (1)
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice, please choose from options." << endl;
        }
    }
    return 0;
}