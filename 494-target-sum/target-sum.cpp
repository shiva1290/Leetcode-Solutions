class Solution {
public:
    int helper(int index,vector<int>&nums,int target){
        if(index==nums.size()){
            if(target==0) return 1;
            return 0;
        }
        int add=helper(index+1,nums,target+nums[index]);
        int subtract=helper(index+1,nums,target-nums[index]);
        return add+subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(0,nums,target);
    }
};