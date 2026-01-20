class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum = INT_MIN;
        for (int i = 0; i < candies.size(); i++) {
            maximum = max(maximum, candies[i]);
        }
        vector<bool> ans(candies.size(), false);
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= maximum) {
                ans[i] = true;
            }
        }
        return ans;
    }
};