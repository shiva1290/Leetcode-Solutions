class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int maxLen=-1;
        unordered_map<char,int> freq;
        int i=0;
        for(int j=0;j<s.size();j++){
            if(freq[s[j]]!=0){
                while(s[i]!=s[j]){
                    freq[s[i]]--;
                    i++;
                }
                i++;
            }
            freq[s[j]]=1;
            maxLen=max(maxLen,j-i+1);
        }
        return maxLen;
    }
};