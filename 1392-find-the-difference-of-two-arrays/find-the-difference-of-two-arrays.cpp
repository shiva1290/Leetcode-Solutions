class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp1;
        unordered_map<int, int> mpp2;
        vector<vector<int>> ans;
        for (auto num : nums1) {
            mpp1[num]++;
        }
        for (auto num : nums2) {
            mpp2[num]++;
        }
        for (int i = 0; i <= 1; i++) {
            if (i == 0) {
                vector<int> temp;
                for (auto& it : mpp1) {
                    if (mpp2[it.first] == 0) {
                        temp.push_back(it.first);
                    }
                }
                ans.push_back(temp);
            } else if (i == 1) {
                vector<int> temp;
                for (auto& it : mpp2) {
                    if (mpp1[it.first] == 0) {
                        temp.push_back(it.first);
                    }
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};