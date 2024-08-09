#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void remove(int value)
    {
        Node *currNode = head;
        Node *prevNode = nullptr;

        while (currNode != nullptr && currNode->data != value)
        {
            prevNode = currNode;
            currNode = currNode->next;
        }

        if (currNode == nullptr)
        {
            cout << "Node with value " << value << " doesn't exist." << endl;
            return;
        }

        if (prevNode == nullptr)
        {
            head = currNode->next;
        }
        else
        {
            prevNode->next = currNode->next;
        }

        delete currNode;
    }

    void display()
    {
        Node *currNode = head;

        while (currNode != nullptr)
        {
            cout << currNode->data << " ";
            currNode = currNode->next;
        }

        cout << endl;
    }
};

int main()
{
    LinkedList myList;

    myList.insert(07);
    myList.insert(12);
    myList.insert(13);
    myList.insert(21);

    myList.display();

    myList.remove(07);

    myList.display();

    return 0;
}