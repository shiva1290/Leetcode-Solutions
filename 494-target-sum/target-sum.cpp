class Solution {
public:
    int helper(int index,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(target > 1000 || target < -1000) return 0;
        if(index==nums.size()){
            if(target==0) return 1;
            return 0;
        }
        int t=1000+target;
        if(dp[index][t]!=-1){
            return dp[index][t];
        }
        int add=helper(index+1,nums,target+nums[index],dp);
        int subtract=helper(index+1,nums,target-nums[index],dp);
        return dp[index][t]=add+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        vector<vector<int>>dp(nums.size()+1,vector<int>(2002,-1));
        return helper(0,nums,target,dp);
    }
};