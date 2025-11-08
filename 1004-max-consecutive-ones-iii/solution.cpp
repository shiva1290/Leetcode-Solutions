class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int flag = k;
        int maxLength = -1;
        int n = nums.size();
        while (j < n) {
            if (nums[j] == 0) {
                flag--;
            }
            while (flag < 0) {
                if (nums[i] == 0)
                    flag++;
                i++;
            }
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        return maxLength;
    }
};