class Solution {
public:
    string minWindow(string s, string t) {
        int startIndex = -1;
        int l = 0;
        int r = 0;
        int freq[256];

        for (char c : t) {
            freq[c]++;
        }

        int cnt = 0;
        int minLen = INT_MAX;

        while (r < s.size()) {

            if (freq[s[r]] > 0) {
                cnt++;
            }

            freq[s[r]]--;
        
            while (cnt == t.size()) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIndex = l;
                }
                freq[s[l]]++;
                if (freq[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }
    return (startIndex==-1) ? "" : s.substr(startIndex,minLen);
    }
};