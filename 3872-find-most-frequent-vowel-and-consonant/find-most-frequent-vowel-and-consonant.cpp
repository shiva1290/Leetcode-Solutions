class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int maxFreqSum(string s) {
        unordered_map<char, int> mpp;
        for (char c : s) {
            mpp[c]++;
        }
        int maxVow = 0;
        int maxCon = 0;
        for (auto& it : mpp) {
            if (isVowel(it.first) && it.second > maxVow) {
                maxVow = it.second;
            } else if (!isVowel(it.first) && it.second > maxCon) {
                maxCon = it.second;
            }
        }
        return maxVow + maxCon;
    }
};