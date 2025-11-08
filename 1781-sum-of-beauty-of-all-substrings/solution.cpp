class Solution {
public:
    int beautySum(string s) {
        int total = 0;

        for (int i = 0; i < s.size(); i++) {
            int mpp[26] = {0};
            for (int j = i; j < s.size(); j++) {
                mpp[s[j] - 'a']++;
                int mx = INT_MIN;
                int mn = INT_MAX;

                for (int k = 0; k < 26; k++) {

                    if (mpp[k] > 0) {
                        mx = max(mx, mpp[k]);
                        mn = min(mn, mpp[k]);
                    }
                }
                total+=mx-mn;
            }
        }
        return total;
    }
};