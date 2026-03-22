class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        bool flag=true;
        int ans=INT_MIN;
        int maxEle=INT_MIN;
        for(auto num : nums){
            maxEle=max(maxEle,num);
            if(num>0){
                flag=false;
            }
            sum+=num;
            if(sum<0){
                sum=0;
            }
            ans=max(ans,sum);
        }
        return (flag) ? maxEle : ans;
    }
};