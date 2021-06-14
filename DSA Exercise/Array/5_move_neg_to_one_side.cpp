#include <iostream>
using namespace std;

// Func to print array array
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to move negative one side and positive integers other side
void move_neg(int arr[], int size)
{
    int arr1[size];
    int j = 0;
    int k = size - 1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            arr1[j] = arr[i];
            j++;
        }
        else
        {
            arr1[k] = arr[i];
            k--;
        }
    }

    printArr(arr1, size);
}

int main()
{
    int arr[] = {-12, 11, 45, 23, -98, -34, 43, -76};
    int s = sizeof(arr) / sizeof(int);
    move_neg(arr, s);
    return 0;
}

