class Solution {
public:
    // int helper(int index1,int index2, string & text1 , string & text2,
    // vector<vector<int>>& dp){
    //     if(index1>=n || index2>=m){
    //         return 0;
    //     }
    //     if(text1[index1]==text2[index2]){
    //         return 1+helper(index1+1,index2+1,text1,text2,dp);
    //     }
    //     if(dp[index1][index2]!=-1){
    //         return dp[index1][index2];
    //     }
    //     int take1=helper(index1,index2+1,text1,text2,dp);
    //     int take2=helper(index1+1,index2,text1,text2,dp);
    //     return dp[index1][index2]=max(take1,take2);
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[n - 1][m - 1] = text1[n - 1] == text2[m - 1];
        for (int i = n - 2; i >= 0; i--) {
            int equals=text1[i] == text2[m - 1];
            dp[i][m - 1] = max  (dp[i + 1][m - 1], equals);
        }
        for (int j = m - 2; j >= 0; j--) {
            int equals= text1[n - 1] == text2[j];
            dp[n - 1][j] = max((dp[n - 1][j + 1]),equals);
        }

        for (int index1 = n - 2; index1 >= 0; index1--) {
            for (int index2 = m - 2; index2 >= 0; index2--) {
                int ans = INT_MIN;
                if (text1[index1] == text2[index2])
                    ans = 1 + dp[index1 + 1][index2 + 1];
                int take1 = dp[index1 + 1][index2];
                int take2 = dp[index1][index2 + 1];
                dp[index1][index2] = max(take1, max(take2, ans));
            }
        }
        return dp[0][0];
    }
};