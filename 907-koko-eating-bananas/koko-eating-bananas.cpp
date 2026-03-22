class Solution {
public:
    long long bsa(vector<int>&nums,int k){
        long long ans=0;
        for(auto num : nums){
            ans+=(num+k-1)/k;
        }
        return ans;
    }
    int helper(int low,vector<int>&nums,int h,int high){
        while(low<=high){
            long long mid=1LL*low+(high-low)/2;
            long long ans=bsa(nums,mid);
            if(ans>h){
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(auto p : piles){
            maxi=max(p,maxi);
        }
        return helper(1,piles,h,maxi);
    }
};