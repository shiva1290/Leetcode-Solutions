class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int sum=0;
       int maxSum=INT_MIN;
       int maxEle=INT_MIN;
       bool negative=true;
       for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
            negative=true;
        }
        maxEle=max(nums[i],maxEle);

        sum+=nums[i];
        if(sum<0){
            sum=0;
        }
        maxSum=max(sum,maxSum);
       }
       if(negative && maxSum==0) return maxEle;
        return maxSum;
    }
};