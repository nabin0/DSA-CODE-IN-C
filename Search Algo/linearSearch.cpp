#include <iostream>
using namespace std;
int binary_search(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {12, 1212, 213334, 2, 3421, 4, 32, 212, 78, 54, 665, 0, 1, 121};
    int size = (sizeof(arr) / sizeof(int));
    int element = 121;
    int val = binary_search(arr, size, element);
    cout << element << " is present at index: " << val << endl;
    return 0;
}


// // Binary search searches by traversal through the array i.e it visits every elements of array one by one and when it finds the element then it returns the value or tells that element is not found if the given element doesnt exists in array then it travels through whole loop and returns that is not found .
// The best case Time complexicity for linear search is O(1) => Constant 
// And the worst case complexixity is O(n) 