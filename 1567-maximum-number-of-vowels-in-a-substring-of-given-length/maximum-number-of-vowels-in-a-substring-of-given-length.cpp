class Solution {
public:
    int isVowel(char c) {
    c = tolower(c);
    if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    return 0;
}

    int maxVowels(string s, int k) {
        int currVow=0;
        int firstChar=0;
        for(int i=0;i<k;i++){
            currVow+=isVowel(s[i]);
        }
        int maxVow=currVow;
        for(int i=k;i<s.size();i++){
            int vowels=currVow-isVowel(s[firstChar])+isVowel(s[i]);
            currVow=vowels;
            if(currVow>maxVow){
                maxVow=currVow;
            }
            firstChar++;
        }

        return maxVow;
    }
};