#include <iostream>
using namespace std;

int binary_search(int arr[], int element, int size)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        if (arr[low] == element)
        {
            return low;
        }
        if (arr[high] == element)
        {
            return high;
        }
        mid = ((low + high) / 2);
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int element, size;
    int arr[] = {1, 12, 14, 17, 52, 86, 99, 121, 132, 144};
    element = 144;
    size = (sizeof(arr) / sizeof(int));
    int val = binary_search(arr, element, size);
    cout << element << " is present at index: " << val << endl;
    return 0;
}