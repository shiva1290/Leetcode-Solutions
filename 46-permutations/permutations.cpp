class Solution {
public:
    void helper(int i, vector<int>& nums, set<vector<int>>& ans) {
        if (i == nums.size())
            return;
        ans.insert(nums);
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            helper(i + 1, nums, ans);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        set<vector<int>> ans;
        helper(0, nums, ans);
        vector<vector<int>> fin;
        for (auto vec : ans) {
            fin.push_back(vec);
        }
        return fin;
    }
};