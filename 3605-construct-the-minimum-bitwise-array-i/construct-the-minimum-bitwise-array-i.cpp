class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        for (int j = 0; j < n; j++) {
            if (nums[j] == 2) {
                arr[j] = -1;
                continue;
            }
            for (int i = 0; i < 1000; i++) {
                if ((i | i + 1) == nums[j]) {
                    arr[j] = i;
                    break;
                }
            }
        }
        return arr;
    }
};