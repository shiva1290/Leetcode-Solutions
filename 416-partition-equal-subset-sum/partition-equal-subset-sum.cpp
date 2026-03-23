class Solution {
public:
    bool helper(int index,vector<int>&nums,int sum,vector<vector<int>>&dp){
        if(index==nums.size()){
            return sum==0;
        }
        if(sum==0){
            return true;
        }
        if(sum<0){
            return false;
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum]==1;
        }
        int take=helper(index+1,nums,sum-nums[index],dp);
        int notTake=helper(index+1,nums,sum,dp);
        return dp[index][sum]= take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto num : nums){
            sum+=num;
        }
        if(sum%2!=0) return false;
        else sum=sum/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum+1,-1));
        return helper(0,nums,sum,dp);
    }
};