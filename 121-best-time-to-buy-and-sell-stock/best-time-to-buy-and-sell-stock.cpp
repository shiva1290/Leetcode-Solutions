class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVar=INT_MAX;
        int maxProfit=INT_MIN;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minVar){
                minVar=prices[i];
            }
            else if(minVar!=INT_MAX && prices[i]>minVar){
                int profit=prices[i]-minVar;
                maxProfit=max(maxProfit,profit);
            }
        }
    return (maxProfit==INT_MIN) ? 0 : maxProfit;
    }
};