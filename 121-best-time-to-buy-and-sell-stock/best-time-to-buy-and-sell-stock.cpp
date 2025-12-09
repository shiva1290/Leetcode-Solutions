class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxprofit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < mini) {
                mini = prices[i];
            }
            int profit = prices[i] - mini;
            maxprofit = max(maxprofit, profit);
        }
        return maxprofit;
    }
};