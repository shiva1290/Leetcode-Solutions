class Solution {
public:
    int maxProfit(int k, vector<int> arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (!buy) {
                        dp[index][buy][cap] =
                            max((-arr[index] + dp[index + 1][1][cap]),
                                0 + dp[index + 1][0][cap]);
                    }

                    if (buy) {
                        dp[index][buy][cap] =
                            max((arr[index] + dp[index + 1][0][cap - 1]),
                                0 + dp[index + 1][1][cap]);
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};
