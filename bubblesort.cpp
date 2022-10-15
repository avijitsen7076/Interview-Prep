#include<bits/stdc++.h>
using namespace std;

void bubblesort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }
}

int main()
{
    int n,*p;
    cin>>n;
    p= new int [n];

    for(int i=0;i<n;i++)
        cin>>p[i];

    cout<<endl;
    bubblesort(p,n);

    for(int i=0;i<n;i++)
        cout<<p[i];
    return 0;
}