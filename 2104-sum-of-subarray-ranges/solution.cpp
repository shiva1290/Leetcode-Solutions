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
 vector<int> ngElement(vector<int> nums) {
        int n = nums.size();
        vector<int> ans(n,n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
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
    vector<int> pgElement(vector<int> nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for (int i =0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
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

    long long subArrayRanges(vector<int> &arr) {
        long long sum = 0;
        vector<int> nse = nsElement(arr);
        vector<int> pse = psElement(arr);
        vector<int> nge = ngElement(arr);
        vector<int> pge = pgElement(arr);
        for (int i = 0; i < arr.size(); i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long left2 = i - pge[i];
            long long right2 = nge[i] - i;
            long long val1 = (left * right * 1LL) * (arr[i] * 1LL);
            long long val2 = (left2 * right2 * 1LL) * (arr[i] * 1LL);
            sum = (sum + val2-val1);
        }
        return sum;
    }
};