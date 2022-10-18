class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string reversed(s);
        reverse(reversed.begin(), reversed.end());
        if(s == reversed) {
                return true;
        }
        return false;
    }
};