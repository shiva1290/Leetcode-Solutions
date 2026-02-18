class Solution {
public:
    int longestCommonSubsequence(string str1, string str2) {
        vector<int>dp(str2.size() + 1, 0);
        for (int ind1 = str1.size() - 1; ind1 >= 0; ind1--) {
            vector<int>temp(str2.size()+1,0);
            for (int ind2 = str2.size() - 1; ind2 >= 0; ind2--) {
                if (str1[ind1] == str2[ind2]) {
                    temp[ind2] = 1 + dp[ind2 + 1];
                } else {
                    temp[ind2] =
                        max(dp[ind2],temp[ind2 + 1]);
                }
            }
            dp=temp;
        }
        return dp[0];
    }
};