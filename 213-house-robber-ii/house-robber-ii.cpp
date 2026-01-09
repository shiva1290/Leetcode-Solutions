class Solution {
public: 
    int helper(vector<int>&nums,int index,vector<int>&dp){
        if(index==0){
            return nums[index];
        }
        
        if(index<0){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }
        int take=nums[index]+helper(nums,index-2,dp);
        int nottake=0+helper(nums,index-1,dp);
        return dp[index]=max(take,nottake);
    }
    int rob(vector<int>& money) {
        vector<int>arr1;
        vector<int>arr2;
        vector<int>dp1(money.size(),-1);
        vector<int>dp2(money.size(),-1);
        if(money.size()==1) return money[0];

        for(int i=0;i<money.size();i++){
            if(i!=0)arr1.push_back(money[i]);
            if(i!=money.size()-1)arr2.push_back(money[i]);
        }
        int ans1=helper(arr1,arr1.size()-1,dp1);
        int ans2=helper(arr2,arr2.size()-1,dp2);
        return max(ans1,ans2);
    }
};
