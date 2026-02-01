class Solution {
public: 
    int helper(int index1,int index2, string & text1 , string & text2, vector<vector<int>>& dp){
        if(index1>=text1.size() || index2>=text2.size()){
            return 0;
        }
        if(text1[index1]==text2[index2]){
            return 1+helper(index1+1,index2+1,text1,text2,dp);
        }
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        int take1=helper(index1,index2+1,text1,text2,dp);
        int take2=helper(index1+1,index2,text1,text2,dp);
        return dp[index1][index2]=max(take1,take2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return helper(0,0,text1,text2,dp);
    }
};