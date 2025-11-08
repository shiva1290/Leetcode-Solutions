class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq=0;
        int maxCount=0;
        int i=0;
        int freq[26] = {0};

        for(int j=0;j<s.size();j++){
            freq[s[j]-'A']++;
            maxFreq=max(maxFreq,(freq[s[j]-'A']));
            while((j-i+1)-maxFreq>k){
                freq[s[i]-'A']--;
                i++;
            }
        maxCount=max(maxCount,(j-i+1));
        }
        return maxCount;
    }
};