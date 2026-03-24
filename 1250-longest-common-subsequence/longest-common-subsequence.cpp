class Solution {
public:
    int helper(int idx1, int idx2, string & text1, string &text2,vector<vector<int>>&dp){
        if(idx1>=text1.size() || idx2>=text2.size()) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        int match=INT_MIN;
        int move1,move2;
        if(text1[idx1]==text2[idx2]) match=1+helper(idx1+1,idx2+1,text1,text2,dp);
        move1=helper(idx1+1,idx2,text1,text2,dp);
        move2=helper(idx1,idx2+1,text1,text2,dp);
        return dp[idx1][idx2]=max(match,max(move1,move2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size(),-1));
        return helper(0,0,text1,text2,dp);
    }
};