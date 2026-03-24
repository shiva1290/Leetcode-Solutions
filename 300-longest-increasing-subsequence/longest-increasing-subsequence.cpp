class Solution {
public:
    int helper(int index,int prev, vector<int>&nums,vector<vector<int>>&dp){
        if(index==nums.size()) return 0;
        if(dp[index][prev+1]!=-1){
            return dp[index][prev+1];
        }
        int take=INT_MIN;
        int notTake;
        if(prev==-1 || nums[prev]<nums[index]) take=1+helper(index+1,index,nums,dp);
        notTake=helper(index+1,prev,nums,dp);
        return dp[index][prev+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        int ans=helper(0,-1,nums,dp);
        return ans;
    }
};