#include <stdio.h>

void displayArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int *,int ,int,int);
void mergeSort(int *arr, int low, int high){
    int mid;
    if (low<high)
    {
        mid = (low + high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid, high);
    }
    
}

void merge(int * arr, int low, int mid, int high){
    int i , j, k, aux[100];
    i=low;
    j=mid+1;
    k=low;
    while (i<=mid && j<=high)
    {
        if (arr[i] < arr[j]){
            aux[k] = arr[i];
            k++;i++;
        }
        else{
            aux[k] = arr[j];
            j++;k++;
        }
    }
    while (i<=mid){
        aux[k]= arr[i];
        k++;i++;
    }
    while (j<=high){
        aux[k]= arr[j];
        k++;j++;
    }
    for (int i = low; i < high+1; i++)
    {
        arr[i] = aux[i];
    }
    
}

int main()
{
    int Arr[] = {12, 12, 34, 56, 78, 98, 65, 342, 13, 2};
    int n = sizeof(Arr) / sizeof(int);
    int low = 0;
    int high = n - 1;
    displayArray(Arr, n);
    mergeSort(Arr, low, high);
    displayArray(Arr, n);
    return 0;
}