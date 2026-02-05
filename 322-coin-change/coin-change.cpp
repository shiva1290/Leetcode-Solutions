class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 1e5));
        for(int coin=0;coin<coins.size();coin++){
            dp[coin][0] = 0;
        }
        for(int am=0;am<=amount;am++){
            if(am%coins[0]==0)
            dp[0][am] = am / coins[0] ;
        }
        for (int index = 1; index < coins.size(); index++) {
            for (int am = 1; am <= amount; am++) {
                int takeAgain = INT_MAX;
                if (am - coins[index] >= 0 && coins[index]!=1e5) {
                    takeAgain = 1 + dp[index][am - coins[index]];
                }
                int notTake = dp[index - 1][am];
                dp[index][am] = min(takeAgain, notTake);
            }
        }

        return dp[coins.size() - 1][amount] == 1e5
                   ? -1
                   : dp[coins.size() - 1][amount];
    }
};
