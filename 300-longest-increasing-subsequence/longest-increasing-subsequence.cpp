class Solution {
public:
    int helper(int index, vector<int>& nums, int lastEle,
               vector<vector<int>>& dp) {
        if (index >= nums.size()) {
            return 0;
        }
        if (dp[index][lastEle + 1] != -1) {
            return dp[index][lastEle + 1];
        }
        int take = 0;
        if (lastEle == -1 || nums[lastEle] < nums[index])
            take = 1 + helper(index + 1, nums, index, dp);
        int notTake = helper(index + 1, nums, lastEle, dp);
        return dp[index][lastEle + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
         vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return helper(0, nums, -1, dp);
    }
};