class Solution {
public:
    int GCD(int a,int b){
        if(b==0){
            return a;
        }
        return GCD(b,a%b);
    }

    string gcdOfStrings(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        if(m>n) gcdOfStrings(str2,str1);
        int mini=GCD(n,m);
        string s;
        int i=1;
        while(i<mini+1){
            if(str1[n-i]==str2[m-i]){
                s+=(str1[n-i]);
            }
            else break;
        i++;
        }
        if(s.size()==0) return "";
        if(s.size()>1) reverse(s.begin(),s.end());
        int j=s.size();
        for(int i=0;i<n;i++){
            if(str1[i]==s[i%j]) continue;
            else return "";
        }
        for(int i=0;i<m;i++){
            if(str2[i]==s[i%j]) continue;
            else return "";
        }
        return s;
    }
};