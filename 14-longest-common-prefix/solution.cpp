class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        sort(str.begin(),str.end());
        int k=str.size();
        string s="";
        int n=str[0].size();
        for(int i=0;i<n;i++){
            if(str[0][i]==str[k-1][i]){
                s+=str[0][i];
            }
            else break;
        }
        return s;
    }
};