class Solution{
public:
    int helper(int index,int buy,vector<int>&arr,int cap,vector<vector<vector<int>>>& dp){
        if(cap==0) return 0;
        if(index==arr.size()) return 0;
        int buyMax=INT_MIN;
        int notBuy=INT_MIN;
        if(dp[index][buy][cap]!=-1){
            return dp[index][buy][cap];
        }
        if(!buy){
            buyMax=max((-arr[index]+helper(index+1,1,arr,cap,dp)),0+helper(index+1,0,arr,cap,dp));
        }

        if(buy){
            notBuy=max((arr[index]+helper(index+1,0,arr,cap-1,dp)),helper(index+1,1,arr,cap,dp));
        }
        return dp[index][buy][cap]=max(buyMax,notBuy);
    }
    int maxProfit(int k,vector<int> arr){
        int n=arr.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
 
        return helper(0,false,arr,k,dp);
    }
};
