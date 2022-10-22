// 198. HOUSE ROBBER:

class Solution
{
public:
    int solve(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            int takehome = nums[i];
            if (i > 1)
                takehome += dp[i - 2];
            int donttake = 0 + dp[i - 1];

            dp[i] = max(takehome, donttake);
        }
        return dp[n - 1];
    }
    int rob(vector<int> &nums)
    {

        return solve(nums);
    }
};