class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int length=0;
        int i=0;
        int j=0;

        unordered_set<char> seen;

        while(j<n){
            if(!seen.count(s[j])){
                seen.insert(s[j]);
                length=max(length,j-i+1);
                j++;
            }
            else {
                seen.erase(s[i]);
                i++;
            }
        }
        return length;
    }
};