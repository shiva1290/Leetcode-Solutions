class Solution {
public:
    int longestCommonSubsequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size() + 1,
                               vector<int>(str2.size() + 1, 0));
        for (int ind1 = str1.size() - 1; ind1 >= 0; ind1--) {
            for (int ind2 = str2.size() - 1; ind2 >= 0; ind2--) {
                if (str1[ind1] == str2[ind2]) {
                    dp[ind1][ind2] = 1 + dp[ind1 + 1][ind2 + 1];
                } else {
                    dp[ind1][ind2] =
                        max(dp[ind1 + 1][ind2], dp[ind1][ind2 + 1]);
                }
            }
        }
        return dp[0][0];
    }
};