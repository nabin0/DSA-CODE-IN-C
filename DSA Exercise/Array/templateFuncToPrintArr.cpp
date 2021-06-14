#include <iostream>
using namespace std;

template <class T>
void printArr(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " " << endl;
    }
}
int main()
{
    float arr[] = {12.32, 43.44, 76, 87.33};
    printArr<float>(arr, 4);
    return 0;
}