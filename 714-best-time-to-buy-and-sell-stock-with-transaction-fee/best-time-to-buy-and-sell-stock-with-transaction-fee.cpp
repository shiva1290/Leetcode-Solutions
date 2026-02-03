class Solution {
public:
    int helper(int index, vector<int>&prices, int fee, bool bought,vector<vector<int>>&dp){
        if(index>=prices.size()){
            return 0;
        }
        int sellBought=INT_MIN;
        int continueBuy=INT_MIN;
        int buyStock=INT_MIN;
        int notBuy=INT_MIN;
        if(dp[index][bought]!=-1){
            return dp[index][bought];
        }
        if(bought){
            sellBought=prices[index]-fee+helper(index+1,prices,fee,0,dp);
            continueBuy=helper(index+1,prices,fee,1,dp);
        }
        if(!bought){
            buyStock=-prices[index]+helper(index+1,prices,fee,1,dp);
            notBuy=helper(index+1,prices,fee,0,dp);
        }
        return dp[index][bought]=max(sellBought,max(continueBuy,max(buyStock,notBuy)));
   }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return helper (0,prices,fee,0,dp);
    }
};