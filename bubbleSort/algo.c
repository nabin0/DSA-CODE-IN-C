#include <stdio.h>

void displayArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n; i++) //For required  Pass
    {
        for (int j = 0; j < n - 1 - i; j++) //for comparition and swapping in each pass
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int *arr, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n; i++) //For required  Pass
    {
        for (int j = 0; j < n - 1 - i; j++) //for comparition and swapping in each pass
        {
            isSorted = 1;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    int Arr[] = {12, 34, 56, 78, 98, 65, 342, 13, 2};
    // int Arr[] = {1, 12, 334, 55};
    int n = sizeof(Arr) / sizeof(int);
    displayArray(Arr, n); //Before Sorting
    bubbleSort(Arr, n);   //Sorting Algorithm
    // bubbleSortAdaptive(Arr, n);   //Adaptive Sorting Algorithm Which can detect sorted arrray and will not apply all operations hence saves time. 
    displayArray(Arr, n); //After Sorting
    return 0;
}