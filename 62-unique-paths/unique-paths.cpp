class Solution {
public:
    bool isSafe(int row,int col,int m,int n){
        if(row<0 || row>=m) return false;
        if(col<0 || col>=n) return false;
        return true;
    }

    int totalWays(int row,int col,int m,int n, vector<vector<int>> &dp){
        if(row==m-1 && col==n-1){
            return 1;
        }
        int ways1=0;
        int ways2=0;
        
        if(dp[row][col]!=-1){
            return dp[row][col];
        }

        if(isSafe(row+1,col,m,n)){
        ways1=totalWays(row+1,col,m,n,dp);
        }
        if(isSafe(row,col+1,m,n)){
        ways2=totalWays(row,col+1,m,n,dp);
        }
        return dp[row][col]=ways1+ways2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return totalWays(0,0,m,n,dp);
    }
};