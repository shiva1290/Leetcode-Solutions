class Solution {
public:
int prime=1e9+7;
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 0; i <= s.size(); i++) {
            dp[i][t.size()] = 1;
        }
        for (int index1 = s.size() - 1; index1 >= 0; index1--) {
            for (int index2 = t.size() - 1; index2 >= 0; index2--) {
                if (s[index1] == t[index2]) {
                    int takeBoth = dp[index1 + 1][index2 + 1];
                    int move1 = dp[index1 + 1][index2];
                    dp[index1][index2] = (takeBoth + move1)%prime;
                } else
                    dp[index1][index2] = dp[index1 + 1][index2];
            }
        }
        return dp[0][0];
    }
};