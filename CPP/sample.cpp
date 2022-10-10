int main()
{
    int n;
    cin >> n;
    int i = 1;

    while (i <= n)
    {
        int number = i;
        int space = i - 1;
        while (space)
        {
            cout << " ";
            space--;
        }
        int j = 1;

        while (j <= (n - i + 1))
        {
            cout << number;
            number++;
            j++;
        }
        cout << endl;
        i++;
    }
}
