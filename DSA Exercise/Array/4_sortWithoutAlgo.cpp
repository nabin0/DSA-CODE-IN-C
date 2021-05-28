#include <bits/stdc++.h>
using namespace std;

void prinData(vector<int> &v)
{
    cout<<"Data in vector is as:"<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

int sortArr(int arr[], int size, int min, int max)
{
int n = max-min+1;
    vector<int> v(n,0);
    for (int i = 0; i < n; i++)
    {
        v[arr[i] - min]++;
    }
    prinData(v);

    return 0;
}

int main()
{
    cout<<"DONE"<<endl;
    int arr[] = {0, 34, 100, 54, 76};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min = 0, max = 100;
    sortArr(arr, size,min,max);
    cout<<"DONE"<<endl;
    return 0;
}