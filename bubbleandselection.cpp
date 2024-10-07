#include <iostream>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[minIndex], arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int choice;

    std::cout << "Enter 1 for Bubble Sort, 2 for Selection Sort: ";
    std::cin >> choice;

    switch(choice) {
        case 1:
            bubbleSort(arr, n);
            std::cout << "Sorted array using Bubble Sort: ";
            break;
        case 2:
            selectionSort(arr, n);
            std::cout << "Sorted array using Selection Sort: ";
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            return 1;
    }

    printArray(arr, n);
    return 0;
}