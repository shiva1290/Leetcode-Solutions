class Solution {
public:
    int helper(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        int mini = INT_MAX;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        for (int ind = i; ind <= j; ind++) {
            int ans = cuts[j + 1] - cuts[i - 1] + helper(i, ind - 1, cuts, dp) +
                      helper(ind + 1, j, cuts, dp);
            mini = min(mini, ans);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        return helper(1, c, cuts, dp);
    }
};