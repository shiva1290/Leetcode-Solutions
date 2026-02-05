class Solution {
public:

    int helper(int index, vector<int>& nums, int currentSum, int target,
               int totalSum, vector<vector<int>>& dp) {
        if (index == nums.size()) {
            return currentSum == target;
        }

        int dpIndex = currentSum + totalSum;

        if (dp[index][dpIndex] != -1) {
            return dp[index][dpIndex];
        }

        int add = helper(index + 1, nums, currentSum + nums[index], target,
                         totalSum, dp);

        int sub = helper(index + 1, nums, currentSum - nums[index], target,
                         totalSum, dp);

        return dp[index][dpIndex] = (add + sub);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, -1));

        return helper(0, nums, 0, target, totalSum, dp);
    }
};