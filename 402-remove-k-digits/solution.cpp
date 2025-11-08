class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char> st;
        if (k == nums.size())
            return "0";
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[i] < st.top() && k > 0) {
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }

        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        while (res.size()!=0 && res.back() == '0') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());

        return (res.empty()) ? "0" : res;
    }
};