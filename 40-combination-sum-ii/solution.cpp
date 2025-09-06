class Solution {
public:
    void helper(vector<int>& candidates, vector<int>& nums,
                vector<vector<int>> &answer, int index, int sum, int target) {
        if (sum == target) {
            answer.push_back(nums);
            return;
        }
        if (sum > target || index == candidates.size()) {
            return;
        }
        nums.push_back(candidates[index]);
        helper(candidates, nums, answer, index + 1, sum + candidates[index],
               target);

        nums.pop_back();
        for (int i = index + 1; i < candidates.size(); i++) {
            if (candidates[i] != candidates[index]) {
                helper(candidates, nums, answer, i, sum, target);
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> nums;
        vector<vector<int>> answer;
        helper(candidates, nums, answer, 0, 0, target);
        return answer;
    }
};