class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3)
            return false;
        int j = nums.size() - 1;
        int i = 0;
        while (i < n - 1 && nums[i] < nums[i + 1]) {
            i++;
        }
        while (j > 0 && nums[j] > nums[j - 1]) {
            j--;
        }
        if (i == 0 || j == n - 1)
            return false;
        if (i >= j)
            return false;
        while (i < n - 1 && nums[i] > nums[i + 1]) {
            i++;
        }
        if (i != j)
            return false;
        return true;
    }
};