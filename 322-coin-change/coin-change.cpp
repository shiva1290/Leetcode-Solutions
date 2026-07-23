class Solution {
public:
    int helper(int x, vector<int>&coins, int amount, vector<vector<int>>&dp){
        if(amount==0) return 0;
        if(x==coins.size()) return 1e9;
        if(dp[x][amount]!=-1) return dp[x][amount];
        int include=1e9;
        if(coins[x]<=amount) {
            include=1+helper(x,coins,amount-coins[x],dp);
        }
        int exclude=helper(x+1,coins,amount,dp);
        return dp[x][amount]=min(include,exclude);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans=helper(0,coins,amount,dp);
        return (ans==1e9) ? -1 : ans;
    }
};