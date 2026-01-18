class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxProfit = 0;
        int mini = arr[0];
        int n=arr.size();
        for (int i = 1; i < n; i++) {
            int curProfit = arr[i] - mini;
            maxProfit = max(maxProfit, curProfit);
            mini = min(mini, arr[i]);
        }
        return maxProfit;
    }
};