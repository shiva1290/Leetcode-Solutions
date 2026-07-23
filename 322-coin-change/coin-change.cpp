class Solution {
public:
    // int helper(int x, vector<int>& coins, int amount, vector<vector<int>>& dp) {
    //     if (amount == 0)
    //         return 0;
    //     if (x == coins.size())
    //         return 1e9;
    //     if (dp[x][amount] != -1)
    //         return dp[x][amount];
    //     int include = 1e9;
    //     if (coins[x] <= amount) {
    //         include = 1 + helper(x, coins, amount - coins[x], dp);
    //     }
    //     int exclude = helper(x + 1, coins, amount, dp);
    //     return dp[x][amount] = min(include, exclude);
    // }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                int include = 1e9;
                if (coins[i] <= j) {
                    include = 1 + dp[i][j - coins[i]];
                }
                int exclude = 1e9;
                if (i > 0) {
                    exclude = dp[i - 1][j];
                }
                dp[i][j] = min(include, exclude);
            }
        }
        return (dp[coins.size() - 1][amount] == 1e9) ? -1 : dp[coins.size()-1][amount];
    }
};