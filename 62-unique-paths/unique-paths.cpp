class Solution {
public:
    bool isSafe(int r,int c,int m,int n){
        if(r<0 || r>=m) return false;
        if(c<0 || c>=n) return false;
        return true;
    }
    int helper(int row,int col,int m,int n,vector<vector<int>>&dp){
        if(row==m-1 && col==n-1){
            return 1;
        }
        if(row>m-1 and col>n-1){
            return 0;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int down=0;
        int right=0;
        if(isSafe(row+1,col,m,n)) down=helper(row+1,col,m,n,dp);    
        if(isSafe(row,col+1,m,n)) right=helper(row,col+1,m,n,dp); 
        return dp[row][col]=right+down;
    }   
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(0,0,m,n,dp);
    }
};