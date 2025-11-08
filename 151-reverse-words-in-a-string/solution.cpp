class Solution {
public:
    string reverseWords(string s) {
         int i=0;
       int j=0;
       int wordStart;

       reverse(s.begin(),s.end());
       while(j<s.size()){
        while(s[j]==' ') j++;
        if(j>=s.size()) break;

        wordStart=i;

        while(j<s.size() && s[j]!=' '){
            s[i]=s[j];
            i++;
            j++;
        }
        reverse(s.begin()+wordStart,s.begin()+i);
        if(i<s.size()) s[i++]=' ';
       }
       if(i>0 and s[i-1]==' ') i--;
       s.resize(i);
       return s;
    }
};