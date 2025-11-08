class Solution {
public:
    int countHomogenous(string s) {
        int n=s.size();
        long long count=1;
        int length=1;
        int mod=1e9+7;

        for(int j=1;j<n;j++){
            if(s[j]==s[j-1]){
                length++;
            }
            else length=1;
            count=(count+length)%mod;
        }
        return count;
    }
};