class Solution {
public:
    int helper(int prevIndex,int index,vector<pair<int,int>>&arr,int n,vector<vector<int>> &dp){
        if(index==n) return 0;
        if(dp[index][prevIndex+1]!=-1) return dp[index][prevIndex+1];
        int take=0;
        int notTake;
      if(prevIndex == -1 || arr[index].second >= arr[prevIndex].second) take= arr[index].second+helper(index,index+1,arr,n,dp);
        notTake=helper(prevIndex,index+1,arr,n,dp);
        return dp[index][prevIndex+1]=max(take,notTake);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        vector<pair<int,int>> arr(n);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<scores.size();i++){
            arr[i]={ages[i],scores[i]};
        }
        sort(arr.begin(),arr.end());
        return helper(-1,0,arr,scores.size(),dp);
    }
};