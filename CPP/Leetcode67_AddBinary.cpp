// Problem Link: https://leetcode.com/problems/add-binary

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1, j = b.length()-1;
        int carry = 0, sum, d1, d2;
        string s = "";
        while(i>=0 || j>=0 || carry > 0)
        {
            if(i>=0)
            {
                d1 = (int)a[i] - 48;
            }
            if(j>=0)
            {
                d2 = (int)b[j] - 48;
            }
            sum = d1 + d2 + carry;
            d1 = 0, d2 = 0;
            carry = 0;
            if(sum == 0)
            {
                s += '0';
            }
            else if(sum == 1)
            {
                s += '1';
            }
            else if(sum == 2)
            {
                s += '0';
                carry = 1;
            }
            else if(sum == 3)
            {
                s += '1';
                carry = 1;
            }
            i--;
            j--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
