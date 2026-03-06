class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<vector<int>> ans;
        for (int k = 0; k < nums.size(); k++) {
            if (k>0 && nums[k] == nums[k - 1])
                continue;
            int i = k+1;
            int j = nums.size() - 1;
            while (i < j) {
                int sum = nums[j] + nums[i] + nums[k];
                if (sum == 0) {
                    st.insert({nums[i], nums[j], nums[k]});
                    i++;
                    j--;
                    while (i<nums.size() && nums[i] == nums[i - 1])
                        i++;
                    while (j>=0 && nums[j] == nums[j + 1])
                        j--;
                } else if (sum < 0) {
                    i++;
                } else
                    j--;
            }
        }
        for (auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};