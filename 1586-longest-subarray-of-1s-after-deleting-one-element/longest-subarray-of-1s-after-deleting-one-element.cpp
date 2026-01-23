class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int lastZero=-1;
        int maxLength=0;
        while (r < nums.size()) {
            if(nums[r]==0) {
                l=lastZero+1;
                lastZero=r;
            }
            maxLength=max(maxLength,r-l);
            r++;
        }
        return maxLength;
    }
};