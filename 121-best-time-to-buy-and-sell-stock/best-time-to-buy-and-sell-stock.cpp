class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxAns=INT_MIN;
        int buy=INT_MAX;
        for(auto num :  prices){
            if(num<buy){
                buy=num;
            }
            maxAns=max(num-buy,maxAns);
        }
        return maxAns;
    }
};