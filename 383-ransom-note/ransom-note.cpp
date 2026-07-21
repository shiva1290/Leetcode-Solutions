class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freqArray[26];
        for(auto ch :  magazine){
            freqArray[ch-'a']++;
        }
        for(auto ch :  ransomNote){
            freqArray[ch-'a']--;
            if(freqArray[ch-'a']<0) return false;
        }
        return true;
    }
};