class Solution {
    int M = 1e9 + 7;
    // int helper(int n,vector<int>&dp){
    //     if(n==0){
    //         return 1;
    //     }
    //     if(n==1){
    //         return 1;
    //     }
    //     if(n==2){
    //         return 2;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     return dp[n]=(2*helper(n-1,dp)%M+helper(n-3,dp)%M)%M;
    // }
public:
    int numTilings(int n) {
        if (n == 1 || n == 2)
            return n;
        if (n == 0)
            return 1;
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = (2 * dp[i - 1] % M + dp[i - 3] % M) % M;
        }
        return dp[n];
    }
};