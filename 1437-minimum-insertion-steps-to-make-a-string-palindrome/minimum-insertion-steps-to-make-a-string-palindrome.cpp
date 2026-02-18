class Solution {
public:
    int minInsertions(string s) {
        string str1 = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> curr(n + 1, 0);
            for (int j = n - 1; j >= 0; j--) {
                if (str1[i] == s[j]) {
                    curr[j] = 1 + dp[j + 1];
                } else {
                    curr[j] = max(dp[j], curr[j + 1]);
                }
            }
            dp = curr;
        }
        return n-dp[0];
    }
};