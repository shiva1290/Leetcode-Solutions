class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        while(!is_sorted(nums.begin(),nums.begin()+n)){
            count++;
            int minSum = INT_MAX;
            int minIndex = -1;

            for (int i = 0; i < n - 1; i++) {
                if (nums[i] + nums[i + 1] < minSum) {
                    minSum = nums[i]+nums[i+1];
                    minIndex = i;
                }
            }
            nums[minIndex] = minSum;
            for (int i = minIndex + 1; i < n-1; i++) {
                nums[i] = nums[i + 1];
            }
            n--;
        }
        return count;
    }
};