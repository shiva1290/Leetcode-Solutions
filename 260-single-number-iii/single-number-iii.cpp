class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }

        ans = ans ^ (ans & (ans - 1));

        int XOR1 = 0;
        int XOR2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & ans) {
                XOR1 ^= nums[i];
            } else {
                XOR2 ^= nums[i];
            }
        }
        if (XOR1 < XOR2)
            return {XOR1, XOR2};
        return {XOR2, XOR1};
    }
};