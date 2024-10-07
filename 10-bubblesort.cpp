#include <iostream>

void bubbleSort(int numbers[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

int main()


{
    int a;
    std::cout << "Enter the number of elements: ";
    std::cin >> a;
    int* numbers = new int[a];
    std::cout << "Enter the elements: ";
    for (int i = 0; i < a; ++i)
    {
        std::cin >> numbers[i];
    }
    bubbleSort(numbers, a);
    for (int i = 0; i < a; ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
