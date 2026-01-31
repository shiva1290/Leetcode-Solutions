class Solution {
public:
    // int helper(int index,vector<int>&cost,vector<int>&dp){
    //     if(index>=cost.size()){
    //         return 0;
    //     }
    //     if(dp[index]!=-1){
    //         return dp[index];
    //     }
    //     int take=cost[index]+helper(index+1,cost,dp);
    //     int notTake=cost[index]+helper(index+2,cost,dp);
    //     return dp[index]=min(take,notTake);
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),0);
        if(cost.size()==1) return 0;
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<cost.size();i++){
        int first=cost[i]+dp[i-1];
        int second=cost[i]+dp[i-2];
        dp[i]=min(first,second);
        }
        return min(dp[cost.size()-1],dp[cost.size()-2]);
    }
};