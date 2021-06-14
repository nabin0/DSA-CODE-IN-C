#include <iostream>
using namespace std;

// Func to print array array
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int *union_arr(int arr1[], int arr2[], int s1, int s2, int *n1)
{
    int i = 0, j = 0, k = 0;
    int *newarr = new int;
    while (i < s1 && j < s2)
    {
        if (arr1[i] == arr2[j])
        {
            newarr[k] = arr1[i];
            i++;
            j++;
            k++;
        }
        else if (arr1[i] > arr2[j])
        {
            newarr[k] = arr2[j];
            j++;
            k++;
        }
        else if (arr1[i] < arr2[j])
        {
            newarr[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            cout << "Something is wrong";
        }
    }
    while (j < s2)
    {
        newarr[k] = arr2[j];
        j++;
        k++;
    }
    while (i < s1)
    {
        newarr[k] = arr1[i];
        i++;
        k++;
    }
    *n1 = k;
    return newarr;
}

// Function for intersection

int *intersec(int arr1[], int arr2[], int s1, int s2, int *n2)
{
    int i = 0, j = 0, k = 0;
    int *newarr = new int;
    while (i < s1 && j < s2)
    {
        if (arr1[i] == arr2[j])
        {
            newarr[k] = arr1[i];
            i++;
            j++;
            k++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            cout << "Something is wrong";
        }
    }
    *n2 = k;
    return newarr;
}

int main()
{
    int arr1[] = {1, 4, 6, 7, 8, 9, 12, 43, 45};
    int arr2[] = {1, 3, 4, 8, 10};
    int arr1S = sizeof(arr1) / sizeof(arr1[0]);
    int arr2S = sizeof(arr2) / sizeof(arr2[0]);
    int n1, n2;

    // Union
    int *newarr = union_arr(arr1, arr2, arr1S, arr2S, &n1);
    cout << "The union is :" << endl;
    printArr(newarr, n1);

    // Intersection
    int *newarr1 = intersec(arr1, arr2, arr1S, arr2S, &n2);
    cout << "The Intersection is :" << endl;
    printArr(newarr1, n2);

    return 0;
}