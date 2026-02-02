class Solution {
public:
    // int helper(int i, int j, string& word1, string& word2,
    //            vector<vector<int>>& dp) {
    //     if (i >= word1.size() || j >= word2.size()) {
    //         if (j < word2.size())
    //             return word2.size() - j;
    //         if (i < word1.size())
    //             return word1.size() - i;
    //         return 0;
    //     }
    //     // if(dp[i][j]!=-1){
    //     //     return dp[i][j];
    //     // }
    //     if (word1[i] == word2[j]) {
    //         return helper(i + 1, j + 1, word1, word2, dp);
    //     }
    //     int ins = 1 + helper(i, j + 1, word1, word2, dp);
    //     int del = 1 + helper(i + 1, j, word1, word2, dp);
    //     int rep = 1 + helper(i + 1, j + 1, word1, word2, dp);
    //     return dp[i][j] = min(ins, min(del, rep));
    // }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for (int i = n; i >= 0; i--) {
           dp[i][m] = n - i;
        }
        for (int j = m; j >= 0; j--) {
            dp[n][j] = m - j;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                    continue;
                }
                int ins = dp[i][j + 1];
                int del = dp[i + 1][j];
                int rep = dp[i + 1][j + 1];
                dp[i][j] = 1 + min(ins, min(del, rep));
            }
        }
        return dp[0][0];
    }
};