class Solution {
public:
    int longestPalindrome(string s) {
        bool oddDone=false;
        unordered_map<char,int> mpp;
        for(auto ch : s){
            mpp[ch]++;
        }
        if(mpp.size()==1){
            return s.size();
        }
        int ansVar=0;
        int maxOdd=INT_MIN;
        vector<pair<int,int>>vec(mpp.begin(),mpp.end());
        sort(vec.begin(),vec.end(),[](auto &a,auto &b){
            return a.second>b.second;
        });
        for(auto it : vec){
            if(it.second%2!=0){
                if(!oddDone){
                    ansVar+=it.second;
                    oddDone=true;
                }
                else ansVar+=it.second-1;
            }
            else ansVar+=it.second;
        }
        return ansVar;
    }

};