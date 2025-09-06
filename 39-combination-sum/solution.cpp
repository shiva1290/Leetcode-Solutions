class Solution {
   public:
    void helper(vector<int>& candidates, int index, int sum, int target,
                vector<int>& nums, vector<vector<int>>& answers) {
        if (sum == target) {
            answers.push_back(nums);
            return;
        }
        if (sum > target|| index == candidates.size()) {
            return;
        }

        nums.push_back(candidates[index]);
        helper(candidates, index, sum + candidates[index], target, nums,
               answers);

        nums.pop_back();
        helper(candidates, index + 1, sum, target, nums, answers);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answers;
        vector<int> nums;
        helper(candidates, 0, 0, target, nums, answers);
        return answers;
    }
};