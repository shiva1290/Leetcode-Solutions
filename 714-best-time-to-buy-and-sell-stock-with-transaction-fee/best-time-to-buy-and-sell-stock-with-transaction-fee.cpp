class Solution {
public:
    int helper(int index, int buy, vector<int>& arr, int fee,
               vector<vector<int>>& dp) {
        if (index == arr.size())
            return 0;
        int buyMax = INT_MIN;
        int sellMax = INT_MIN;
        if (dp[index][buy] != -1) {
            return dp[index][buy];
        }
        if (!buy) {
            buyMax = max((-arr[index] + helper(index + 1, 1, arr, fee, dp)),
                         (0 + helper(index + 1, 0, arr, fee, dp)));
        }
        if (buy) {
            sellMax =
                max((arr[index] - fee + helper(index + 1, 0, arr, fee, dp)),
                    (0 + helper(index + 1, 1, arr, fee, dp)));
        }
        return dp[index][buy] = max(buyMax, sellMax);
    }
    int maxProfit(vector<int> arr, int fee) {
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 0, arr, fee, dp);
    }
};