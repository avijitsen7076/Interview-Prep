// 322. COIN CHANGE:

class Solution
{
public:
    int maxcoin(vector<int> &coins, int n, int w)
    {

        int dp[n + 1][w + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < w + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = (j == 0) ? 0 : INT_MAX - 1;
                }
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < w + 1; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][w];
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();

        int ans = maxcoin(coins, n, amount);

        return (ans == INT_MAX - 1) ? -1 : ans;
    }
};