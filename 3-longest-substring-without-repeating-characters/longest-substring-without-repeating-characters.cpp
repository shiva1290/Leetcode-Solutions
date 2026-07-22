class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     unordered_map<char,int> freq;
     int prevIndex=0;
     int maxLength=0;
     for(int i=0;i<s.size();i++){
        freq[s[i]]++;
        while(prevIndex<i && freq[s[i]]!=1){
            freq[s[prevIndex]]--;
            prevIndex++;
        }
        maxLength=max(maxLength,i-prevIndex+1);
     }
     return maxLength;
    }
};