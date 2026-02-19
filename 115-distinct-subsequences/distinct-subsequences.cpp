class Solution {
public:
int prime=1e9+7;
    int numDistinct(string s, string t) {
        vector<int>dp (t.size() + 1, 0);
        dp[t.size()]=1;
        for (int index1 = s.size() - 1; index1 >= 0; index1--) {
            vector<int>curr (t.size() + 1, 0);
            curr[t.size()]=1;
            for (int index2 = t.size() - 1; index2 >= 0; index2--) {
                if (s[index1] == t[index2]) {
                    int takeBoth = dp[index2 + 1];
                    int move1 = dp[index2];
                    curr[index2] = (takeBoth + move1)%prime;
                } else
                    curr[index2] = dp[index2];
            }
            dp=curr;
        }
        return dp[0];
    }
};