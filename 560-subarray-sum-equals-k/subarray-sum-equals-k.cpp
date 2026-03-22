class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int s = 0;
        int ans = 0;
        mpp[0] = 1;

        for (auto num : nums) {
            s += num;
            if (mpp.find(s - k) != mpp.end()) {
                ans += mpp[s - k];
            }
            mpp[s]++;
        }
        return ans;
    }
};