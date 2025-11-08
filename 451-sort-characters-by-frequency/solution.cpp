class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        for (char c : s) mpp[c]++;

        vector<pair<char, int>> vec(mpp.begin(), mpp.end());

        sort(vec.begin(), vec.end(),
             [](auto& a, auto& b) { return a.second > b.second; });

        string res;
        for (int i = 0; i < vec.size(); i++) {
            for(int j=0;j<vec[i].second;j++){
            res+=(vec[i].first);
            }
        }
        return res;
    }
};