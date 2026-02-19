class Solution {
public:
    bool helper(int index1, int index2, string& str, string& pat,vector<vector<int>>&dp) {
        if (index1 == str.size()) {

            while (index2 < pat.size()) {
                if (pat[index2] != '*')
                    return false;
                index2++;
            }
            return true;
        }
        if (index2 >= pat.size()) {
            return index1 == str.size();
        }
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        if (str[index1] != pat[index2] && pat[index2] != '*' &&
            pat[index2] != '?') {
            return false;
        } else if (pat[index2] == '?') {
            return dp[index1][index2]=helper(index1 + 1, index2 + 1, str, pat,dp);
        } else if (pat[index2] == '*') {
            return dp[index1][index2]=(helper(index1, index2 + 1, str, pat,dp) ||
                   helper(index1+1,index2, str, pat,dp));
        }
        return helper(index1 + 1, index2 + 1, str, pat,dp);
    }
    bool isMatch(string s, string p) { 
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return helper(0, 0, s, p,dp); }
};