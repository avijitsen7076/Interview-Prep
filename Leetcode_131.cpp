// 131. PALINDROME PERTITIONING:

class Solution
{
public:
    bool ispalindrome(string s, int st, int end)
    {
        while (st <= end)
        {
            if (s[st] != s[end])
                return false;

            st++;
            end--;
        }
        return true;
    }

    void solve(int index, vector<vector<string>> &ans, vector<string> &path, string s)
    {
        if (index == s.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            if (ispalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i - index + 1));
                solve(i + 1, ans, path, s);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0, ans, path, s);
        return ans;
    }
};