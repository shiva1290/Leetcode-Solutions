class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int buy=INT_MAX;
       int maxProfit=0;
       for(auto n : prices){
        if(n<buy) buy=n;
        else maxProfit=max(maxProfit,n-buy);
       }
       return (maxProfit==INT_MAX) ? 0 : maxProfit;
    }
};