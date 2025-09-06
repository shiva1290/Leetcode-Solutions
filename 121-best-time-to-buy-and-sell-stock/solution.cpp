class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int profit=0;
    int buy=0;
    for(int i=1;i<prices.size();i++){
        if(prices[i]>prices[buy]){
            profit=max(profit,prices[i] - prices[buy]);
        }
        else buy=i;
    } 
    return profit;
    }
};