class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            leftpq;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            rightpq;

        int l = 0;
        int r = costs.size() - 1;

        for (int i = 0; i < candidates && l <= r; i++) {
            leftpq.push({costs[l], l});
            l++;
        }

        for (int i = 0; i < candidates && l <= r; i++) {
            rightpq.push({costs[r], r});
            r--;
        }
        long long ans = 0;
        while (k--) {
            pair<int, int> left = {INT_MAX, INT_MAX};
            pair<int, int> right = {INT_MAX, INT_MAX};
            if (leftpq.size() != 0)
                left = leftpq.top();
            if (rightpq.size() != 0)
                right = rightpq.top();

            if (left.first < right.first ||
                (left.first == right.first && left.second < right.second)) {
                ans += left.first;
                leftpq.pop();
                if (l <= r)
                    leftpq.push({costs[l], l});
                l++;
            } else if (right.first < left.first ||
                       (right.first == left.first &&
                        right.second < left.second)) {
                ans += right.first;
                rightpq.pop();
                if (l <= r)
                    rightpq.push({costs[r], r});
                r--;
            }
        }
        return ans;
    }
};