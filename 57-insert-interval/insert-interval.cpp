class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool pushed = false;
        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (end < newInterval[0] || start > newInterval[1]) {
                if (start > newInterval[1] && !pushed) {
                    ans.push_back(newInterval);
                    pushed = true;
                }
                ans.push_back({start, end});
                continue;
            } else {
                newInterval[0] = min(newInterval[0], start);
                newInterval[1] = max(newInterval[1], end);
            }
        }
        if(!pushed) ans.push_back(newInterval);
        return ans;
    }
};