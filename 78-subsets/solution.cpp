class Solution {
   public:
    void helper(vector<int>& nums, vector<int>& arr,
                vector<vector<int>>& answer, int index) {
        answer.push_back(arr);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            arr.push_back(nums[i]);
            helper(nums, arr, answer, i + 1);
            arr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        vector<int> arr;
        helper(nums, arr, answer, 0);
        return answer;
    }
};