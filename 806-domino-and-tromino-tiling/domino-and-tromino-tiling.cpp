class Solution {
int M=1e9+7;
int helper(int n,vector<int>&dp){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=(2*helper(n-1,dp)%M+helper(n-3,dp)%M)%M;
}
public:
    int numTilings(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};