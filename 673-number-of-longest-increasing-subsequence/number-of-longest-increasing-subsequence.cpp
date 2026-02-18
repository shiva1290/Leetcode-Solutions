class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxLen=0;
        for (int index = 0; index < n; index++) {
            for (int prevIndex = 0; prevIndex < index; prevIndex++) {
                if (nums[prevIndex] < nums[index]) {
                    if (dp[index] < dp[prevIndex] + 1) {
                        dp[index] = dp[prevIndex]+1;
                        count[index] = count[prevIndex];
                    } else if (dp[index] == dp[prevIndex] + 1) {
                        count[index] += count[prevIndex];
                    }
                }
            }
            maxLen=max(maxLen,dp[index]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxLen){
                ans+=count[i];
            }
        }
        return ans;
    }
};