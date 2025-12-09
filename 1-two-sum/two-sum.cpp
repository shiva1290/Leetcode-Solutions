class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int ele = target - nums[i];
            if (mpp.find(ele)!=mpp.end()) {
                return {mpp[ele], i};
            } else {
                mpp[nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};