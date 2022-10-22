// 87. SCRAMBLE STRING:

class Solution
{
public:
    unordered_map<string, bool> mp;
    bool isScramble1(string s1, string s2)
    {
        if (s1.compare(s2) == 0)
        {
            return true;
        }

        int n = s1.length();
        string key = s1 + " " + s2;
        if (mp.find(key) != mp.end())
        {
            return mp[key];
        }
        bool flag = false;
        for (int i = 1; i < n; i++)
        {

            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n - i), s2.substr(i, n - i))) || (isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i, n - i), s2.substr(0, n - i))))
            {
                flag = true;
                break;
            }
        }
        return mp[key] = flag;
    }
    bool isScramble(string s1, string s2)
    {
        if (s1.length() != s2.length())
        {
            return false;
        }

        return isScramble1(s1, s2);
    }
};