class Solution {
public:
     long long Calcdays(vector<int> nums, long long number) {
        long long totalhours = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalhours += ceil((double)nums[i] / (double)number);
        }
        return totalhours;
    }

    int minEatingSpeed(vector<int>& nums, int h) {
        int low = 1;
        int ans = 0;
        int high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long res = Calcdays(nums, mid);
            if (res <= h) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};