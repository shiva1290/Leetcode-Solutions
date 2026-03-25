class Solution {
public:
    void helper(int index,vector<int>&nums,vector<int>ans,vector<vector<int>>&finalans,int target){
        if(target<0) return;
        if(index==nums.size()){
            if(target==0) finalans.push_back(ans);
            return;
        }
        ans.push_back(nums[index]);
        helper(index,nums,ans,finalans,target-nums[index]);
        ans.pop_back();
        helper(index+1,nums,ans,finalans,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>finalans;
        vector<int>ans;
        helper(0,candidates,ans,finalans,target);
        return finalans;
    }
};