#include<iostream>
#include<vector>
using namespace std;

// Function to print a vector
void printVec(vector<int>  &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
}

// Function to sort an Array
void sortArr(int arr[],int size, int min, int max ){
    int n = max - min +1;

    vector<int> v(n, 0);
    for (int i = 0; i < size; i++)
    v[arr[i] - min]++;

    cout<<"Printing vector"<<endl;
    printVec(v); //Calling function to ptint vector

    for (int i=0; i<n; i++)
	for (int j=0; j < v[i]; j++)
	cout << (i + min) << " ";

    cout<<endl;

}

int main(){

int arr[] = {11,7,10,23,10};
int min = 0, max = 23;
int size = sizeof(arr)/sizeof(int);
cout<<"Calling function"<<endl;
sortArr(arr,size,min,max);
cout<<"Code Executed"<<endl;
return 0;
}





