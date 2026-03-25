class Solution {
public:
    void helper(int index,vector<int>&nums,vector<int>ans,vector<vector<int>>&finalans){
        if(index==nums.size()){
            finalans.push_back(ans);
            return;
        }
        ans.push_back(nums[index]);
        helper(index+1,nums,ans,finalans);
        ans.pop_back();
        helper(index+1,nums,ans,finalans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>> finalans;
        helper(0,nums,ans,finalans);
        return finalans;
    }
};