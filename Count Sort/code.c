#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void displayArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int maximum(int arr[], int n)
{
    int min = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (min < arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}
void countSort(int *arr, int n)
{
    int i, j;
    int max = maximum(arr, n);
    int *aux = (int *)malloc(max + 1 * sizeof(int));

    for (i = 0; i <= max + 1; i++)
    {
        aux[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        aux[arr[i]] = aux[arr[i]] + 1;
    }
    i = 0;
    j = 0;
    while (i <= max)
    {
        if (aux[i] > 0)
        {
            arr[j] = i;
            aux[i] = aux[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int Arr[] = {12, 12, 34, 56, 78, 98, 65, 342, 13, 2};
    int n = sizeof(Arr) / sizeof(int);
    // int Arr[] = {12, 12, 45, 8, 23, 2};
    // int n = 6;
    displayArray(Arr, n);
    countSort(Arr, n);
    displayArray(Arr, n);
    return 0;
}