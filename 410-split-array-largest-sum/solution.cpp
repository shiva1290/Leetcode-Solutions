class Solution {
public:
    int countStudentfunc(vector<int>& nums, int high) {
        int n = nums.size();
        int count = 1;
        int pages = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] + pages <= high) {
                pages += nums[i];
            } else {
                count++;
                pages = nums[i];
            }
        }
        return count;
    }

    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (m > n)
            return -1;
        int low = INT_MIN;
        int high = 0;
        int countStudent = 0;

        for (int i = 0; i < n; i++) {
            low = max(low, nums[i]);
            high += nums[i];
        }

        int result = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            countStudent = countStudentfunc(nums, mid);
            if (countStudent > m) {
                low = mid + 1;
            } else {
                result = mid;
                high = mid - 1;
            }
        }
        return result;
    }
};