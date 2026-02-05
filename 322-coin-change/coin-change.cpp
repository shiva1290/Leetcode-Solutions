class Solution {
   public:
    int helper(int index, vector<int>& coins, int amount,vector<vector<int>>&dp) {
        if (amount == 0) {
            return 0;
        }
        if (index >= coins.size()) {
            return 1e9;
        }
		if(dp[index][amount]!=-1)
		{
			return dp[index][amount];
		}
        int takeAgain = INT_MAX;
        if (amount - coins[index] >= 0) {
            takeAgain = 1 + helper(index, coins, amount - coins[index],dp);
        }
        int notTake = helper(index + 1, coins, amount,dp);
        return dp[index][amount]=min(takeAgain, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
		vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
		int ans= (helper(0, coins, amount,dp));
        return ans==1e9 ? -1 : ans;
    }
};
