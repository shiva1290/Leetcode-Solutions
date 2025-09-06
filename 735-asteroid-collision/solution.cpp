class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> s;
        for (int x : a) {
            while (!s.empty() && x < 0 && s.back() > 0 && s.back() < -x) {
                s.pop_back();
            }
            if (s.empty() || x > 0 || s.back() < 0)
                s.push_back(x);
            else if (s.back() == -x)
                s.pop_back();
        }
        return s;
    }
};
