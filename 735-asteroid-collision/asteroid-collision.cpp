class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int i = 0;
        while (i < asteroids.size()) {
            bool destroyed = false;
            while (!st.empty() && asteroids[i] < 0 && st.back() > 0) {
                if (st.back() < abs(asteroids[i])) {
                    st.pop_back();
                    continue;
                }
                if (st.back() > abs(asteroids[i])) {
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    st.pop_back();
                    break;
                }
            }

            if (!destroyed) {
                st.push_back(asteroids[i]);
            }
            i++;
        }
        return st;
    }
};