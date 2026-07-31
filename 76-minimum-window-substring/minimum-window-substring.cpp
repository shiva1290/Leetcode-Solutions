class Solution {
public:
    bool containsWord(unordered_map<char, int>& mpp,
                      unordered_map<char, int>& mpp2) {
        for (auto& [key, value] : mpp) {
            if (mpp2[key] < value)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        if (t.length() > s.length())
            return "";
        int i = 0;
        unordered_map<char, int> mpp;
        unordered_map<char, int> mpp2;
        for (auto ch : t) {
            mpp[ch]++;
        }
        int minLength = INT_MAX;
        int start=-1;
        string ans;
        for (int j = 0; j < s.size(); j++) {
            mpp2[s[j]]++;
            while (i<=j && containsWord(mpp, mpp2)) {
                if (minLength > j - i + 1) {
                    minLength=j-i+1;
                    start=i;
                }
                mpp2[s[i]]--;
                i++;
            }
        }
        return (start==-1) ? "" : s.substr(start,minLength);
    }
};