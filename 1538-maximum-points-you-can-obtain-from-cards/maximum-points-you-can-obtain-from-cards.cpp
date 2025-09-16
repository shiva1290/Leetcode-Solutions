class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
         int n=nums.size();
    int leftSum=0;

    for(int i=0;i<=k-1;i++){
        leftSum+=nums[i];
    }

    int maxSum=leftSum;
    int rightSum=0;
    int rightIndex=n-1;

    for(int i=k-1;i>=0;i--){
        leftSum-=nums[i];
        rightSum+=nums[rightIndex];
        maxSum=max(maxSum,leftSum+rightSum);
        rightIndex--;
        }
    return maxSum;
    }
};