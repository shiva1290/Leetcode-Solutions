class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxSum=INT_MIN;
        int maxEle=INT_MIN;
        bool pos=false;
        for(auto num :  nums){
            if(num>0) pos=true;
            maxEle=max(maxEle,num);
            sum+=num;
            if(sum<0){
                sum=0;
            }
            maxSum=max(maxSum,sum);
        }
        return (pos) ? maxSum : maxEle;
    }
};