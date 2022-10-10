int reverse(int n)
{ // 123//
    int rev = 0, lastdigit = 0;
    while (n > 0)
    {                               // 12//1
        lastdigit = n % 10;         // 3//2//1
        rev = 10 * rev + lastdigit; // 3//32//321
        n /= 10;                    // 12//1
    }
    return rev;
}

