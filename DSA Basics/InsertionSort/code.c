#include<stdio.h>

void displayArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int * arr, int n){
    int j, key;
    for (int i = 1; i <= n-1; i++)
    {
        key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j] > key )
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
}

int main(){
    // int Arr[] = {12, 34, 56, 78, 98, 65, 342, 13, 2};
    int Arr[] = {1111, 4322, 133,354,544,56,57,76};
    int n = sizeof(Arr)/sizeof(int);
    displayArray(Arr,n);
    insertionSort(Arr,n);
    displayArray(Arr,n);
return 0;
}