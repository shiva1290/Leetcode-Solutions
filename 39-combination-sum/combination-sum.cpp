class Solution {
public:
    void helper(int index,vector<int>temp,vector<int>& candidates, int target,vector<vector<int>>&ans){
        if(index==candidates.size()) return;
        if(target<=0){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(candidates[index]);
        helper(index,temp,candidates,target-candidates[index],ans);
        temp.pop_back();
        helper(index+1,temp,candidates,target,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0,temp,candidates,target,ans);
        return ans;
    }
};