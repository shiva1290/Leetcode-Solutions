class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        int longest = 0;
        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int x = num;
                int cnt = 1;
                while (st.find(x + 1) != st.end()) {
                    x=x+1;
                    cnt++;
                }
             longest = max(longest, cnt);
            }
        }
        return longest;
    }
};