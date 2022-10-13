
#include <bits/stdc++.h>
using namespace std;

int maxWater(int arr[], int n)
{

    int left = 0;
    int right = n - 1;
    int l_max = 0;
    int r_max = 0;
    int result = 0;
    while (left <= right)
    {
        if (r_max <= l_max)
        {
            result += max(0, r_max - arr[right]);
            r_max = max(r_max, arr[right]);
            right -= 1;
        }
        else
        {

            result += max(0, l_max - arr[left]);
            l_max = max(l_max, arr[left]);
            left += 1;
        }
    }
    return result;
}

int main()
{
    int N;
    cout << "Enter the size of the array:- " << endl;
    cin >> N;
    int arr[N];
    cout << "Enter the array values for the elevation :- " << endl;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << "The Answer Is:- " << maxWater(arr, N) << endl;
    return 0;
}
