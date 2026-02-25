class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mpp;
        vector<string> orig;
        orig = strs;
        for (auto &s : strs) {
            sort(s.begin(), s.end());
        }

        int index = 0;
        int k = 0;
        vector<int> num(strs.size());

        for (const auto& s : strs) {
            if (mpp.find(s) != mpp.end()) {
                num[k] = mpp[s];
            }

            else {
                mpp[s] = index;
                num[k] = mpp[s];
                index++;
            }

            k++;
        }

        vector<vector<string>> ans(index, vector<string>(0, ""));
        for (int i = 0; i < strs.size(); i++) {
            ans[num[i]].push_back(orig[i]);
        }
        return ans;
    }
};