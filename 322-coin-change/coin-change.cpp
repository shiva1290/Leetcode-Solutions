class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount + 1, 1e5);
        for(int am=0;am<=amount;am++){
            if(am%coins[0]==0)
            dp[am] = am / coins[0] ;
        }
        for (int index = 1; index < coins.size(); index++) {
            vector<int>curr(amount+1,1e5);
            curr[0]=0;
            for (int am = 1; am <= amount; am++) {
                int takeAgain = INT_MAX;
                if (am - coins[index] >= 0) {
                    takeAgain = 1 + curr[am - coins[index]];
                }
                int notTake = dp[am];
                curr[am] = min(takeAgain, notTake);
            }
            dp=curr;
        }

        return dp[amount] == 1e5
                   ? -1
                   : dp[amount];
    }
};
