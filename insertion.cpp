#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int *arr,int n)
{
    int i,j,k;
    for(i=1;i<n;i++)
    {
        j=i-1;
        int x=arr[i];

        while(x<arr[j] && j>-1)
        {
            //swap(arr[j+1],arr[j]);
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
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
    insertion_sort(p,n);

    for(int i=0;i<n;i++)
        cout<<p[i];
    return 0;
}