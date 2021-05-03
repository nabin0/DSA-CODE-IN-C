#include <stdio.h>
void displayArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, int n)
{
    int indexOfMin, temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[indexOfMin] > arr[j])
            {
                indexOfMin = j;
            }
        }
        temp = arr[indexOfMin];
        arr[indexOfMin] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    int Arr[] = {12, 34, 56, 78, 98, 65, 342, 13, 2};
    int n = sizeof(Arr) / sizeof(int);
    displayArray(Arr, n);
    selectionSort(Arr,n);
    displayArray(Arr, n);
    return 0;
}