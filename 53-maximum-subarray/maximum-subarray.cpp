class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int allneg=true;
        int sum=0;
        int minNeg=INT_MIN;
        int ans=INT_MIN;
        for(auto n : nums){
            if(n>=0) allneg=false;
            if(allneg){
                minNeg=max(minNeg,n);
            }
            sum+=n;
            if(sum<0){
                sum=0;
            }
            ans=max(sum,ans);
        }
        return (allneg) ? minNeg : ans;
    }
};