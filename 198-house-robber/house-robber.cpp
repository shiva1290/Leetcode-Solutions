class Solution {
public:
    int helper(int index,vector<int>&nums,vector<int>&dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int take=nums[index]+helper(index+2,nums,dp);
        int notTake=0+helper(index+1,nums,dp);
        return dp[index]=max(take,notTake);
    }

    int rob(vector<int>& nums) {
    vector<int>dp(nums.size(),-1);
    int first= helper(0,nums,dp);
    int second= helper(1,nums,dp);
    return max(first,second);
    }
};