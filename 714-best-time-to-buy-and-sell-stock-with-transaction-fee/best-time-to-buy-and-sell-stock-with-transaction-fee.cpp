class Solution {
public:
    //     int helper(int index, vector<int>&prices, int fee, bool
    //     bought,vector<vector<int>>&dp){
    //         if(index>=prices.size()){
    //             return 0;
    //         }
    //         int sellBought=INT_MIN;
    //         int continueBuy=INT_MIN;
    //         int buyStock=INT_MIN;
    //         int notBuy=INT_MIN;
    //         if(dp[index][bought]!=-1){
    //             return dp[index][bought];
    //         }
    //         if(bought){
    //             sellBought=prices[index]-fee+helper(index+1,prices,fee,0,dp);
    //             continueBuy=helper(index+1,prices,fee,1,dp);
    //         }
    //         if(!bought){
    //             buyStock=-prices[index]+helper(index+1,prices,fee,1,dp);
    //             notBuy=helper(index+1,prices,fee,0,dp);
    //         }
    //         return
    //         dp[index][bought]=max(sellBought,max(continueBuy,max(buyStock,notBuy)));
    //    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][1]=dp[n][0]=0;
        for (int index = n - 1 ; index >= 0; index--) {
            for (int bought = 1; bought >= 0; bought--) {
                int sellBought = INT_MIN;
                int continueBuy = INT_MIN;
                int buyStock = INT_MIN;
                int notBuy = INT_MIN;
                if (bought) {
                    sellBought = prices[index] - fee + dp[index + 1][0];
                    continueBuy = dp[index + 1][1];
                }
                if (!bought) {
                    buyStock = -prices[index] + dp[index + 1][1];
                    notBuy = dp[index + 1][0];
                }
                dp[index][bought] = max(
                           sellBought, max(continueBuy, max(buyStock, notBuy)));
            }
        }
        return dp[0][0];
    }
};