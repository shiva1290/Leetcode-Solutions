class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int i = 0;
        while (i < asteroids.size()) {
            bool destroyed = false;
            while (!st.empty() && asteroids[i] < 0 && st.top() > 0) {
                if (st.top() < abs(asteroids[i])) {
                    st.pop();
                    continue;
                }
                if (st.top() > abs(asteroids[i])) {
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    st.pop();
                    break;
                }
            }

            if (!destroyed) {
                st.push(asteroids[i]);
            }
            i++;
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};