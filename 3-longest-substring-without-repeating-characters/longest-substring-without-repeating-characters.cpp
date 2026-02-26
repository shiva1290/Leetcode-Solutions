class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int left=0;
        int maxLen=1;
       unordered_map<char,int> mpp;
       mpp[s[0]]=0;

        for(int i=1;i<s.size();i++){
            if(mpp.find(s[i])!=mpp.end() && mpp[s[i]]>=left){
                left=mpp[s[i]]+1;
                cout<<s[i]<<" ";
            }
            maxLen=max(maxLen,i-left+1);
           mpp[s[i]]=i;
        }
        return maxLen;
    }
};