#include<iostream>
#include<vector>
using namespace std;

void sortArr(int arr[],int size, int min, int max ){
    int n = max - min +1;

    vector<int> v(n, 0);
    for (int i = 0; i < size; i++)
    v[arr[i] - min]++;

    for (int i=0; i<n; i++)
	for (int j=0; j < v[i]; j++)
	cout << (i + min) << " ";

    cout<<endl;

}

int main(){

int arr[] = {1,2,0};
int min = 0, max = 2;
int size = sizeof(arr)/sizeof(int);
cout<<"Calling function"<<endl;
sortArr(arr,size,min,max);
cout<<"Code Executed"<<endl;
return 0;
}





