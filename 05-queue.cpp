#include <iostream>

#define MAX_SIZE 100

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot enqueue element." << std::endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        arr[rear] = value;
        std::cout << "Enqueued element: " << value << std::endl;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue element." << std::endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        std::cout << "Dequeued element." << std::endl;
    }

    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No front element." << std::endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            std::cout << "Queue is empty. No rear element." << std::endl;
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Queue queue;
    int value;
    
    std::cout << "Enter elements to enqueue (enter -1 to stop):" << std::endl;
    while (true) {
        std::cin >> value;
        if (value == -1) {
            break;
        }
        queue.enqueue(value);
    }
    
    std::cout << "Front element: " << queue.getFront() << std::endl;
    std::cout << "Rear element: " << queue.getRear() << std::endl;
    
    queue.dequeue();
    
    std::cout << "Front element: " << queue.getFront() << std::endl;
    std::cout << "Rear element: " << queue.getRear() << std::endl;
    
    return 0;
}