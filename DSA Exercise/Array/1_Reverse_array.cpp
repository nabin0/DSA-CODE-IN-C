// ---------------Method 1-------------------
/*
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {12, 34, 65, 3, 87, 33};
    int size_of_arr = sizeof(arr) / sizeof(int);
    int rev_arr[size_of_arr];
    int j = 0;
    for (int i = size_of_arr - 1; i >= 0; i--)
    {
        rev_arr[j] = arr[i];
        j++;
    }
    for (int i = 0; i < size_of_arr; i++)

    {
        cout << rev_arr[i] << " ";
    }

    return 0;
}

*/

// ---------------Method 2-------------------

#include <iostream>
using namespace std;

void rev_array(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {12, 34, 65, 3, 87, 33};
    int size_of_arr = sizeof(arr) / sizeof(int);
    int start = 0;
    int end = size_of_arr - 1;
    cout << "\nArray Before Reversing:" << endl;
    printArr(arr, size_of_arr);
    rev_array(arr, start, end);
    cout << "\nArray After Reversing:" << endl;
    printArr(arr, size_of_arr);
    return 0;
}