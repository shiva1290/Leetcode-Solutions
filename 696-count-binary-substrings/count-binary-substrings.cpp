class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]!=s[i+1]){
                int lc=1;
                int rc=1;
                int left=i;
                int right=i+1;
                while(left>0 && s[left]==s[left-1]){
                    lc++;
                    left--;
                }
                while(right<s.size()-1 && s[right]==s[right+1]){
                    rc++;
                    right++;
                }
            ans+=min(lc,rc);
            }
        }
        return ans;
    }
};