class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (auto &i:mpp) {
            pq.push({i.second, i.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int>v;
        while (!pq.empty()) {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};