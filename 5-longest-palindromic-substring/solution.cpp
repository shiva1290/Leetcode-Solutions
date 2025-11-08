class Solution {
public:
    int expand(string s,int l,int r){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
    if(s.empty()) return " ";
    int maxLen=INT_MIN;
    int start=0;
    int end=0;

    for(int i=0;i<s.size();i++){
        int len1=expand(s,i,i);
        int len2=expand(s,i,i+1);
        int maxLen=max(len1,len2);
        if(maxLen>end-start+1){
            start=i-((maxLen-1)/2);
            end=i+(maxLen/2);
            }
        }
    return s.substr(start, end - start + 1);
    }
};