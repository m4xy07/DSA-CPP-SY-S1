#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            return false;
        }
    }
    return true;
}

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int key)
{
    if (!isSorted(arr, size))
    {
        cout << "Error: Array is not sorted. Binary search cannot be performed." << endl;
        return -1;
    }
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int key;
    int choice;

    cout << "Enter the element to search: ";
    cin >> key;
    cout << "Choose search method: 1 for Linear Search, 2 for Binary Search: ";
    cin >> choice;

    int result = -1;
    switch (choice)
    {
    case 1:
        result = linearSearch(arr, size, key);
        break;
    case 2:
        result = binarySearch(arr, size, key);
        break;
    default:
        cout << "Invalid choice!" << endl;
        delete[] arr;
        return 1;
    }

    if (result != -1)
    {
        cout << "Element found at index " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    delete[] arr;
    return 0;
}