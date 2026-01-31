class Solution {
public:
    int helper(int n,unordered_map<int,int>&dp){
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        if(n==0){
            return 0;
        } 
        if(n==1 || n==2){
            return 1;
        }

        int result = helper(n-1,dp)+helper(n-2,dp)+helper(n-3,dp);
        dp[n]=result;
        return result;
    }
    int tribonacci(int n) {
        unordered_map<int,int>dp;
        return helper(n,dp);
    }
};