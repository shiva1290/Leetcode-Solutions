class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int n = nums.size();
        int position = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[position] = nums[i];
                position++;
            }
        }
        while (position < n) {
            nums[position] = 0;
            position++;
        }
    }
};