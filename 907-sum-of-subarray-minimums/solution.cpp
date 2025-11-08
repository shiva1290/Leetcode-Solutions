class Solution {
   public:
    vector<int> nsElement(vector<int> nums) {
        int n = nums.size();
        vector<int> ans(n,n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty())
                ans[i] = (n);
            else
                ans[i] = (st.top());
            st.push(i);
        }
        return ans;
    }
    vector<int> psElement(vector<int> nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for (int i =0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (st.empty())
                ans[i] = (-1);
            else
                ans[i] = (st.top());
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int> &arr) {
        int sum = 0;
        vector<int> nse = nsElement(arr);
        vector<int> pse = psElement(arr);

        int mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long val = (left * right * 1LL) * (arr[i] * 1LL) % mod;
            sum = (sum + val) % mod;
        }
        return sum;
    }
};
