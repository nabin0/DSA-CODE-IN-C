#include <stdio.h>
void displayArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int temp;
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    // displayArray(arr, 3);


    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    } while (i < j);
    temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    return j;
};

void quickSort(int arr[], int l, int h)
{
    int partitionIndex;
    if (l < h)
    {
        partitionIndex = partition(arr, l, h);
        quickSort(arr, l, partitionIndex - 1); //Sorting left side array of pivot point
        quickSort(arr, partitionIndex + 1, h); //Sorting right side array of pivot point
    }
}
int main()
{
    int Arr[] = {12,12, 34, 56, 78, 98, 65, 342, 13, 2};
    int n = sizeof(Arr) / sizeof(int);
    int low = 0;
    int high = n - 1;
    displayArray(Arr, n);
    quickSort(Arr, low, high);
    displayArray(Arr, n);
    return 0;
}