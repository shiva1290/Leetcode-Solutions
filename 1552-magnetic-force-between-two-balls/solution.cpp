class Solution {
public:
 bool canwePlace(vector<int> &nums, int distance, int cows) {
        int n = nums.size();
        int cntCows = 1;
        int last = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] - last >= distance) {
                cntCows++;
                last = nums[i];
            }
            if (cntCows >= cows) return true;
        }
        return false;
    }
 
    int maxDistance(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mini = nums[0];
        int maxi = nums[n - 1];
        int low = 0;
        int high = maxi - mini;
        int ans=0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canwePlace(nums, mid, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};