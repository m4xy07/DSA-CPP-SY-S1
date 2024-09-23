#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList() : head(nullptr) {}

    Node *createNode(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        return newNode;
    }

    void insertFront(int data)
    {
        Node *newNode = createNode(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << data << " inserted at the front." << endl;
    }

    void insertEnd(int data)
    {
        Node *newNode = createNode(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << data << " inserted at the end." << endl;
    }

    void deleteFront()
    {
        if (head == nullptr)
        {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        cout << temp->data << " deleted from the front." << endl;
        delete temp;
    }

    void deleteEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        Node *temp = head;
        if (temp->next == nullptr)
        {
            head = nullptr;
        }
        else
        {
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->prev->next = nullptr;
        }
        cout << temp->data << " deleted from the end." << endl;
        delete temp;
    }

    void displayForward()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        cout << "List (Forward): ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        cout << "List (Backward): ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList dll;

    dll.insertFront(10);
    dll.insertFront(20);
    dll.insertEnd(30);
    dll.insertEnd(40);

    dll.displayForward();
    dll.displayBackward();

    dll.deleteFront();
    dll.deleteEnd();

    dll.displayForward();
    dll.displayBackward();

    return 0;
}
