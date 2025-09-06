class Solution {
public:
    int helper(vector<int> nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int last = nums[high];
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return target;
            }
            if (nums[mid] < target) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return last;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int answer = helper(mat[mid], target);
            if (answer == target)
                return true;
            if (answer < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};