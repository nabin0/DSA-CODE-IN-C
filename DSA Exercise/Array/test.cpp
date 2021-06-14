#include<iostream>
using namespace std;

int main(){
int *arr = new int;
int s = sizeof(arr);
int j = 0;
while(j <5)
{
    arr[j] = 121;
    j++;
}
for (int i = 0; i < 5; i++)
{
    cout<<arr[i]<<" ";
}
cout<<arr[3]<<endl;
return 0;
}