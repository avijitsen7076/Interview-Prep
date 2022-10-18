int FindBinarySearch(int arr[], int n, int key)
{

    int start = 0;
    int end = n - 1;
    int mid = start + ((end - start) / 2);
    while (start <= end)
    {

        if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        mid = start + ((end - start) / 2);
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;

    cout << FindBinarySearch(arr, n, key);
}
