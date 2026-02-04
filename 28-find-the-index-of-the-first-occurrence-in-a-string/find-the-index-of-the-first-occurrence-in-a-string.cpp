class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        if(n<m) return -1;
        for(int i=0;i<n-m+1;i++){
            bool flag=true;
            for(int j=0;j<m && i+j<n;j++){
                if(haystack[i+j]!=needle[j]){
                    flag=false;
                }
            }
            if(flag) return i;
        }
        return -1;
    }
};