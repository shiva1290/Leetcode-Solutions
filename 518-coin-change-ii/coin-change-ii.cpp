class Solution {
public:
     public:
    int helper(int index, vector<int>& nums, int amount,
               vector<vector<int>>& dp) {
        if(amount==0){
          return 1;
        }
        if(amount<0){
          return 0;
        }
        if (index == nums.size()) {
            return amount==0;
        }

        if (dp[index][amount] != -1) {
            return dp[index][amount];
        }

        int add = helper(index, nums, amount-nums[index], dp);
        int ignore = helper(index + 1, nums, amount, dp);

        return dp[index][amount] = (add+ignore);
    }

    int change(int amount,vector<int>& coins) {
        int N=coins.size();
        vector<vector<int>> dp(N, vector<int>(amount + 1, -1));
        return helper(0, coins, amount, dp);
    }
};