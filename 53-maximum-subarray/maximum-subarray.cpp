class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        int maxi=INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
        maxi=max(maxi,nums[i]);
            sum += nums[i];
        if (sum < 0) {
            sum = 0;
        }
        maxSum = max(maxSum, sum);
    }
    return (maxSum==0) ? maxi : maxSum;
}
}
;