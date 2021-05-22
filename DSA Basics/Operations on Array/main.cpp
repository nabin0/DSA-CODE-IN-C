#include <iostream>
using namespace std;

void insertElems(int arr[], int size)
{
  cout << "Set value of elements in array" << endl;
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
};

void traverseArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int indexInsertion(int arr[], int index, int element, int size, int capacity)
{
  if (size >= capacity)
  {
    return -1;
  }
  for (int i = size - 1; i >= index; i--)
  {
    arr[i + 1] = arr[i];
  }
  arr[index] = element;
  return 1;
}
int indexDeletion(int arr[], int index, int size)
{
  for (int i = index; i < size - 1; i++)
  {
    arr[i] = arr[i + 1];
  }
  return 1;
}

int main()
{
  cout << "Let's Create Array First..." << endl;
  cout << "Enter The Size of Array You want To reserve. NOTE: You Can Enter Amount of size greater then you want to use now if you want to add items later on it." << endl;
  int n, size;
  cin >> n;
  n = n - 1;
  int arr[n];
  cout << "Now Enter the Size of array you want to use. NOTE: This should be smaller then Array Size." << endl;
  cin >> size;
  // size = size - 1;
  int capacity = n, index, element, position;
  insertElems(arr, size);
  while (1)
  {
    char inpCtrl;
    cout << "This is your array: Please select any operation you want to use..." << endl;
    traverseArray(arr, size);
    cout << "Enter 'i' or 'I' for Insertion and for deleting any element enter 'd' or 'D' and 'q' or 'Q' to close the program." << endl;
    cin >> inpCtrl;
    if ((inpCtrl == 'q') || (inpCtrl == 'Q'))
    {
      break;
    }
    else{
    cout << "Enter the position of element you want to apply operation on: eg. [11, 23, 453] 23 is in 2nd position. " << endl;
    cin >> position;
    index = position - 1;
    if ((inpCtrl == 'i') || (inpCtrl == 'I'))
    {
      cout << "Enter the value You want to add in the array." << endl;
      cin >> element;
      cout << "Before Insertion" << endl;
      traverseArray(arr, size);
      indexInsertion(arr, index, element, size, capacity);
      size += 1;
      cout << "Before Insertion" << endl;
      traverseArray(arr, size);
    }
    else if ((inpCtrl == 'd') || (inpCtrl == 'D'))
    {
      indexDeletion(arr, index, size);
      size -= 1;
      traverseArray(arr, size);
    }
    else
    {
      cout << "Why Are You Entering Invalid Input HUH!!!" << endl;
    }
  }}

  return 0;
}