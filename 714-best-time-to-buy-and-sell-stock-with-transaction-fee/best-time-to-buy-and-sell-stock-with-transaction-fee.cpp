class Solution {
public:
    // int helper(int index, int buy, vector<int>& arr, int fee,
    //            vector<vector<int>>& dp) {
    //     if (index == arr.size())
    //         return 0;
    //     int buyMax = INT_MIN;
    //     int sellMax = INT_MIN;
    //     if (dp[index][buy] != -1) {
    //         return dp[index][buy];
    //     }
    //     if (!buy) {
    //         buyMax = max((-arr[index] + helper(index + 1, 1, arr, fee, dp)),
    //                      (0 + helper(index + 1, 0, arr, fee, dp)));
    //     }
    //     if (buy) {
    //         sellMax =
    //             max((arr[index] - fee + helper(index + 1, 0, arr, fee, dp)),
    //                 (0 + helper(index + 1, 1, arr, fee, dp)));
    //     }
    // //     return dp[index][buy] = max(buyMax, sellMax);
    // }
    int maxProfit(vector<int> arr, int fee) {
        int n=arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (!buy) {
                    dp[index][buy] =
                        max((-arr[index] + dp[index+1][1]),
                            (0 + dp[index+1][0]));
                }
                if (buy) {
                     dp[index][buy] = max(
                        (arr[index] - fee + dp[index+1][0]),
                        (0 + dp[index+1][1]));
                }
            }
        }
        return dp[0][0];
    }
};