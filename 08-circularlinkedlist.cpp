#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void deleteNode(int key) {
        if (!head) return;

        if (head->data == key && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* last = head;
        Node* d = nullptr;

        if (head->data == key) {
            while (last->next != head) {
                last = last->next;
            }
            last->next = head->next;
            delete head;
            head = last->next;
        } else {
            while (last->next != head && last->next->data != key) {
                last = last->next;
            }

            if (last->next->data == key) {
                d = last->next;
                last->next = d->next;
                delete d;
            }
        }
    }

    void display() {
        if (!head) return;

        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtBeginning(5);
    cll.display();

    cll.deleteNode(20);
    cll.display();

    return 0;
}