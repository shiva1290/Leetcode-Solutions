class Solution {
public:
    int helper(vector<int>& money) {
        vector<int> dp(money.size(), -1);
        dp[0] = money[0];
        int neg = 0;
        for (int i = 1; i < money.size(); i++) {
            int pick = money[i];
            if (i > 1)
                pick += dp[i - 2];
            int notpick = 0 + dp[i - 1];
            dp[i] = max(pick, notpick);
        }
        return dp[money.size()-1];
    }

    int rob(vector<int> & money) {
            vector<int> arr1;
            vector<int> arr2;
            if (money.size() == 1)
                return money[0];

            for (int i = 0; i < money.size(); i++) {
                if (i != 0)
                    arr1.push_back(money[i]);
                if (i != money.size() - 1)
                    arr2.push_back(money[i]);
            }
            int ans1 = helper(arr1);
            int ans2 = helper(arr2);
            return max(ans1, ans2);
    }
};
