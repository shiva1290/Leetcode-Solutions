class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        vector<int> dp(n, 1);
        vector<int> parent(n);
        int maxLen = 0;
        int lastInd = 0;
        for (int index = 0; index < n; index++) {
            parent[index] = index;
            for (int lastIndex = 0; lastIndex < index; lastIndex++) {
                if ((nums[index] % nums[lastIndex] == 0 &&
                     dp[index]<dp[lastIndex]+1)) {
                    dp[index] = dp[lastIndex] + 1;
                    parent[index] = lastIndex;
                }
            }
            if (dp[index] > maxLen) {
                maxLen = dp[index];
                lastInd = index;
            }
        }
        int i = lastInd;
        while (i != parent[i]) {
            ans.push_back(nums[i]);
            i = parent[i];
        }
        ans.push_back(nums[i]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};