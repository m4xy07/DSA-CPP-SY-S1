#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBegin(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAtPosition(int value, int position) {
        if (position <= 0) {
            insertAtBegin(value);
        } else {
            Node* newNode = new Node(value);
            Node* current = head;
            int currentPosition = 0;

            while (current != nullptr && currentPosition < position - 1) {
                current = current->next;
                currentPosition++;
            }

            if (current != nullptr) {
                newNode->next = current->next;
                current->next = newNode;
            } else {
                std::cout << "Invalid position!" << std::endl;
            }
        }
    }

    void deleteAtBegin() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }


    void deleteAtEnd() {
        if (head != nullptr) {
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
            } else {
                Node* current = head;
                while (current->next->next != nullptr) {
                    current = current->next;
                }
                delete current->next;
                current->next = nullptr;
            }
        }
    }

    void deleteAtPosition(int position) {
        if (position <= 0) {
            deleteAtBegin();
        } else {
            Node* current = head;
            Node* previous = nullptr;
            int currentPosition = 0;

            while (current != nullptr && currentPosition < position) {
                previous = current;
                current = current->next;
                currentPosition++;
            }

            if (current != nullptr) {
                if (previous != nullptr) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
            } else {
                std::cout << "Invalid position!" << std::endl;
            }
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList linkedList;

    linkedList.insertAtBegin(10);
    linkedList.insertAtEnd(20);
    linkedList.insertAtEnd(30);
    linkedList.insertAtPosition(15, 1);

    linkedList.display();

    linkedList.deleteAtBegin();
    linkedList.deleteAtEnd();
    linkedList.deleteAtPosition(1);

    linkedList.display();

    return 0;
}