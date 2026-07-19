class Solution {
public:
    bool isPalindrome(string s) {
        string newString;
        for(auto ch :  s){
            if(isalnum(ch)) newString.push_back(tolower(ch));
        }
        string orig=newString;
        reverse(newString.begin(),newString.end());
        return orig==newString;
    }
};