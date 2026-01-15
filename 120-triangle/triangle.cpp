class Solution {
public:
int solve(int row, int col , vector<vector<int>>& triangle,vector<vector<int>>&dp){
        if(row==0){
            return triangle[0][0];
        }
        int upLeft=INT_MAX;
        int up=INT_MAX;
        
        if(dp[row][col]!=-1){
            return dp[row][col];
        }

        if(col <= row-1){
        up=triangle[row][col]+solve(row-1,col,triangle,dp);
        }
        if(col-1>=0){
        upLeft=triangle[row][col]+solve(row-1,col-1,triangle,dp);
        }
        return dp[row][col]=min(up,upLeft);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
    int n=triangle.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int minAns=INT_MAX;
        for(int i=0;i<n;i++){
           int ans = solve(n-1,i,triangle,dp);
           minAns=min(ans,minAns);
        }
        return minAns;
    }
    
};