class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
    int n=words.size();
    vector<int>result;
    for(int i=0;i<n;i++){
        string s=words[i];
        if(s.find(x)!=string::npos){
            result.push_back(i);
        }
    }
    return result;
    }
};