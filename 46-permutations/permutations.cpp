class Solution {
public:
    void helper(int start,int end,vector<int>& nums,vector<vector<int>>&finalans){
        if(start==end){
            finalans.push_back(nums);
            return;
        }
        for(int i=start;i<end;i++){
        swap(nums[start], nums[i]);
        helper(start + 1, end, nums, finalans);
        swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>finalans;
        helper(0,nums.size(),nums,finalans);
        return finalans;
    }
};