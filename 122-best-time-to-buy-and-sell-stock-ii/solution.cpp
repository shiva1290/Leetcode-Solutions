class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int maxi = -1;
        int mini = INT_MAX;

        for (int i = 0; i < n - 1; i++) { 
            if (prices[i] < prices[i + 1] && mini == INT_MAX) {
                mini = prices[i]; 
            }
            else if (prices[i] > prices[i + 1] && mini != INT_MAX) {
                maxi = prices[i];
                profit += maxi - mini;
                mini = INT_MAX; 
            }
        }
        if (mini != INT_MAX) {
            maxi = prices[n - 1];
            profit += maxi - mini;
        }

        return profit;
    }
};
