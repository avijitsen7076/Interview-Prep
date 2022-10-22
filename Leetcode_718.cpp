// 718. Maximum Length of Repeated Subarray:

class Solution
{
public:
    int solve(vector<int> &nums1, vector<int> &nums2)
    {

        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    int val = 1 + dp[i - 1][j - 1];
                    dp[i][j] = val;
                    ans = max(ans, val);
                }
                else
                    dp[i][j] = 0;
            }
        }

        return ans;
    }
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {

        return solve(nums1, nums2);
    }
};