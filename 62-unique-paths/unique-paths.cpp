class Solution {
public:
    bool isValid(int r, int c, int m, int n){
        if(r<0 || r>=m) return false;
        if(c<0 || c>=n) return false;
        return true;
    }
    int helper(int r, int c,int m,int n,vector<vector<int>>&dp){
        if(r>=m || c>=n) return 0;
        if(r==m-1 && c==n-1) return 1;
        if(dp[r][c]!=-1) return dp[r][c];
        int left=0;
        int right=0;
        if(isValid(r+1,c,m,n)) left=helper(r+1,c,m,n,dp);
        if(isValid(r,c+1,m,n)) right=helper(r,c+1,m,n,dp);
        return dp[r][c]=left+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(0,0,m,n,dp);
    }
};