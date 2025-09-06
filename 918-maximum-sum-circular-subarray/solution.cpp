class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int arraySum = nums[0];

        int sum = nums[0];  
        int maxSum = nums[0];

        int sumMin = nums[0]; 
        int minSum = nums[0];

        for(int i = 1; i < n; i++) {
            arraySum += nums[i];

            sum = max(nums[i], sum + nums[i]);
            maxSum = max(sum, maxSum);

            sumMin = min(nums[i], sumMin + nums[i]);
            minSum = min(sumMin, minSum);
        }

        if(arraySum == minSum) {
            return maxSum;
        }

        return max(maxSum, arraySum - minSum);
    }
};
