class Solution {
public:
    int helper(vector<int> nums, int mid, int k) {
        int n=nums.size();
        int bloomed=0;
        int numbouq=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=mid){
                bloomed++;
            }
            else {
                numbouq+=bloomed/k;
                bloomed=0;
            }
        }
        numbouq+=bloomed/k;
        return numbouq;
    }
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();

        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        int required = 1LL * k * m;

        if (required > n) return -1;

        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int res = helper(nums, mid, k);
            if (res >= m) {
                ans = mid;
                high = mid-1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};