class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        if(nums.size()==1) return false;

        for (int i = 0; i < nums.size(); i++) {
            if (mpp.find(nums[i]) != mpp.end()) {
                if (abs(i - mpp[nums[i]]) <= k) {
                    return true;
                }
            }
            mpp[nums[i]] = i;
        }
        return false;
    }
};