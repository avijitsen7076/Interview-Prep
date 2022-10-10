
int fibseries(int a, int b, int n)
{
    int sum = 0;
    for (int i = 1; i <= (n - 2); i++)
    {
        sum = a + b;
        cout << sum << " ";
        a = b;
        b = sum;
    }
}
