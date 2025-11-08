class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string res;
        for(char ch: s){
            if (ch=='('){
                cnt++;
                if(cnt>1) res+='(';
            }
            else {
                cnt--;
                if(cnt>0) res+=')';
            }
        }
        return res;
    }
};