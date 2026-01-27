class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int target = 0;
        if (arr.size() == 1)
            return false;
        for (int i = 0; i < arr.size(); i++) {
            target += arr[i];
        }
        if (target % 2 != 0)
            return false;
        vector<bool> prev((target / 2) + 1, false);

        prev[0] = true;

        if (arr[0] <= target / 2) {
            prev[arr[0]] = true;
        }
        for (int index = 1; index < n; index++) {
            vector<bool> curr((target / 2) + 1, false);
            for (int k = 1; k <= target / 2; k++) {

                if (arr[index] <= k) {
                    curr[k] = prev[k] || prev[k - arr[index]];
                } else {
                    curr[k] = prev[k];
                }
            }
            prev = curr;
        }
        return prev[target / 2];
    }
};