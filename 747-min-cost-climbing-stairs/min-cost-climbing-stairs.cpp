class Solution {
public:
    int helper(int index,vector<int>&cost,vector<int>&dp){
        if(index>=cost.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int take=cost[index]+helper(index+1,cost,dp);
        int notTake=cost[index]+helper(index+2,cost,dp);
        return dp[index]=min(take,notTake);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
        int first=helper(0,cost,dp);
        int second=helper(1,cost,dp);
        return min(first,second);
    }
};