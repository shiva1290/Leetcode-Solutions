class Solution {
public:
    int helper(int index1, int index2, string& word1, string& word2,vector<vector<int>>&dp){
        if(index1>=word1.size() || index2>=word2.size()){
            if(index1>=word1.size() && index2<word2.size()){
                return word2.size()-index2;
            }
            if(index2>=word2.size() && index1<word1.size()){
                return word1.size()-index1;
            }
            else return 0;
        }
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        if(word1[index1]==word2[index2]){
            return helper(index1+1,index2+1,word1,word2,dp);
        }
        int ins=1+helper(index1,index2+1,word1,word2,dp);
        int del=1+helper(index1+1,index2,word1,word2,dp);
        int rep=1+helper(index1+1,index2+1,word1,word2,dp);
        return dp[index1][index2]=min(ins,min(del,rep));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return helper(0,0,word1,word2,dp);
    }
};