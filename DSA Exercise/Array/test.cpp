#include <iostream>
using namespace std;

void printArr(int arr[])
{

    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {1, 4, 5, 3, 9};
    printArr(arr);
    return 0;
}