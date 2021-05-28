#include <iostream>
#include <algorithm>
using namespace std;

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " << endl;
    }
}

int kth_max(int arr[], int size, int k)
{
    sort(arr, arr + size, greater<int>());
    if (k < size)
    {
        return arr[k - 1];
    }
    return 0;
}
int kth_min(int arr[], int size, int k)
{
    sort(arr, arr + size);
    if (k < size)
    {
        return arr[k - 1];
    }
    return 0;
}

int main()
{
    int arr[] = {12, 43, 54, 1, 31, 123, 998, 456};
    int size = sizeof(arr) / sizeof(arr[0]);
    // printArr(arr,size);
    int k = 2;
    cout << "The maximun value at " << k << "th position is: " << kth_max(arr, size, k) << endl;
    cout << "The minimum value at " << k << "th position is: " << kth_min(arr, size, k) << endl;
    return 0;
}