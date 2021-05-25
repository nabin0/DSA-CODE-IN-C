#include<iostream>
using namespace std;

int max(int arr[], int size){
    int max_elem = arr[0];
    for (int i = 0; i < size; i++){
        if (max_elem < arr[i])
        {
            max_elem=arr[i];
        }
    }
    return max_elem;
}
int min(int arr[], int size){
    int min_elem = arr[0];
    for (int i = 0; i < size; i++){
        if (min_elem > arr[i])
        {
           min_elem=arr[i];
        }
    }
    return min_elem;
}

int main(){

int arr[] = {1,4,23,12,56,32,11,98,-72,76,32};
int size = sizeof(arr)/sizeof(int);
cout<<"The Maximum element in this array is: "<<max(arr, size)<<endl;
cout<<"The Minimum element in this array is: "<<min(arr, size)<<endl;
return 0;
}