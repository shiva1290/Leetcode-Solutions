class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int target = 0;
        if (arr.size() == 1)
            return false;
        for (int i = 0; i < arr.size(); i++) {
            target += arr[i];
        }
        if (target % 2 != 0)
            return false;
        vector<vector<bool>> dp(n, vector<bool>((target / 2) + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        if (arr[0] <= target / 2) {
            dp[0][arr[0]] = true;
        }
        for (int index = 1; index < n; index++) {
            for (int k = 1; k <= target / 2; k++) {
                if (arr[index] <= k) {
                    dp[index][k] =
                        dp[index - 1][k] || dp[index - 1][k - arr[index]];
                } else {
                    dp[index][k] = dp[index - 1][k];
                } 
            }
        }
        return dp[n - 1][target / 2];
    }
};