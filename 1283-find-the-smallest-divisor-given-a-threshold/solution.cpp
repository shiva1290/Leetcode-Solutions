class Solution {
public:
 int helper(vector <int>&nums, int mid) {
        int n = nums.size();
        int mul = 0;
        for (int i = 0; i < n; i++) {
            mul += (nums[i] + mid - 1) / mid; 
        }
        return mul;
    }

    int smallestDivisor(vector<int> &nums, int limit) {
        int n = nums.size();
        if(n>limit) return -1;
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int ans = helper(nums, mid);
            if (ans <= limit) {
                high = mid - 1;
            } else low = mid + 1;
        }
        return low;
    }
};