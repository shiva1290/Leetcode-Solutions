class Solution {
public:
    bool isPalindrome(int x) {
    string s=to_string(x);
    int a=0;
    int n=s.size()-1;
    while(a<n){
        if(s[a]!=s[n]){
            return false;
        }
        a++;
        n--;
    }
    return true;
    }
};