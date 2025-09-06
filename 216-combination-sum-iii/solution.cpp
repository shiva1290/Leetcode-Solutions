class Solution {
   public:
    void helper(int index, int sum, vector<int>& nums, vector<int>& temp,
                vector<vector<int>>& res, int k, int n) {
        if (temp.size()==k && sum == n) {
            res.push_back(temp);
            return;
        }
        if (index == 9 || sum > n || temp.size()>k) {
            return;
        }

        temp.push_back(nums[index]);
        helper(index + 1, sum + nums[index], nums, temp, res, k, n);
        temp.pop_back();

        helper(index + 1, sum, nums, temp, res, k, n);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> temp;
        vector<vector<int>> result;
        helper(0, 0, nums, temp, result, k, n);
        return result;
    }
};