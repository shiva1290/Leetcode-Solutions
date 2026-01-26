class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        if(n!=m) return false;

        unordered_map<char,int> mpp1;
        unordered_map<char,int> mpp2;

        for(auto charac : word1){
            mpp1[charac]++;
        }
        for(auto charac : word2){
            mpp2[charac]++;
        }
        unordered_map<int,int> freq1;
        for(auto &freq : mpp1){
            freq1[freq.second]++;
        }
        for(auto &freq : mpp2){
            if(mpp1[freq.first]==0) return false;
            if(freq1[freq.second]==0) return false;
            freq1[freq.second]--;
        }
        return true;
    }
};