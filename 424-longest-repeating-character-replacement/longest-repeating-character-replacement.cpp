class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq=0;
        int maxCount=0;
        int i=0;
        unordered_map<char,int> mpp;
        for(int j=0;j<s.size();j++){
            mpp[s[j]]++;
            maxFreq=max(maxFreq,(mpp[s[j]]));
            while((j-i+1)-maxFreq>k){
                mpp[s[i]]--;
                i++;
            }
        maxCount=max(maxCount,(j-i+1));
        }
        return maxCount;
    }
};