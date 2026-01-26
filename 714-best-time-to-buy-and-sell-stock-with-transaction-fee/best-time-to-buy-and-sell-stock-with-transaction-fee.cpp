class Solution {
public:
    int maxProfit(vector<int> arr, int fee) {
        int n = arr.size();
        vector<int> curr(2, 0);
        vector<int> prev(2, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (!buy) {
                    curr[buy] = max((-arr[index] + prev[1]), (0 + prev[0]));
                }
                if (buy) {
                    curr[buy] =
                        max((arr[index] - fee + prev[0]), (0 + prev[1]));
                }
                prev = curr;
            }
        }
        return curr[0];
    }
};