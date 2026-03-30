class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int maxLen=0;
        int j=0;
        
        for(int i=0;i<s.size();i++){
        mpp[s[i]]++;
            if(mpp[s[i]]!=1){
               while(mpp[s[i]] > 1){
                    mpp[s[j]]--;
                    j++;
                }
            }
        maxLen=max(maxLen,i-j+1);
        }
        return maxLen;
    }
};