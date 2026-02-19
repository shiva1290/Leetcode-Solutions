class Solution {
public:
    int helper(int index1, int index2, string& s, string& t,vector<vector<int>>&dp) {
        if (index2 == t.size()) {
            return 1;
        }
        if (index1 == s.size()) {
            return 0;
        }
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        if (s[index1] == t[index2]) {
            int takeBoth = helper(index1 + 1, index2 + 1, s, t,dp);
            int move1 = helper(index1 + 1, index2, s, t,dp);
            return dp[index1][index2]=takeBoth + move1;
        }
        return dp[index1][index2]=helper(index1 + 1, index2, s, t,dp);
    }

    int numDistinct(string s, string t) { 
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size(),-1));
        return helper(0, 0, s, t,dp);
         }
};