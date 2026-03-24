class Solution {
public:
    int helper(int r,int c,int n,int m, vector<vector<int>>&dp){
        if(r==n-1 && c==m-1){
            return 1;
        }
        if(r>n-1 || c>m-1){
            return 0;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int down=0;
        int right=0;
        if(r+1<n) down=helper(r+1,c,n,m,dp);
        if(c+1<m) right=helper(r,c+1,n,m,dp);
        return dp[r][c]=down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,n,m,dp);
    }
};