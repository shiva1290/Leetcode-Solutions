class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int start = 1;
        int end = 1;
        int j = 0;
        int k = n - 1;
        int result = INT_MIN;
        while (j < n) {
            if (start == 0)
                start = 1;
            if (end == 0)
                end = 1;
            start *= nums[j];
            j++;
            end *= nums[k];
            k--;
            result = (max(result, max(start, end)));
        }
        return result;
    }
};