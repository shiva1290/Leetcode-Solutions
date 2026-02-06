class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[i] = 1;
            }
        }

        for (int index = 1; index < coins.size(); index++) {
            vector<unsigned long long> curr(amount + 1, 0);
            curr[0] = 1;
            for (int amt = 1; amt <= amount; amt++) {
                unsigned long long add = 0;
                if (amt >= coins[index])
                    add = curr[amt - coins[index]];
                unsigned long long ignore = dp[amt];
                curr[amt] = (add + ignore);
            }
            dp = curr;
        }
        return (int)dp[amount];
    }
};