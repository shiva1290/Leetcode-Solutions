class Solution {
public:
    bool isPalindrome(string name, int i, int s) {
        while (i < s) {
            if (name[i++] != name[s--]) {
                return false;
            }
        }
        return true;
    }

    void helper(string s,vector<vector<string>> &result,vector<string>&temp,int index){
        int n=s.size();
        if(index>=n){
            result.push_back(temp);
            return;
        }

        for(int i=index;i<n;i++){
             if(isPalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                helper(s,result,temp,i+1);
                temp.pop_back();
             }

        }
    }

    
    vector<vector<string>> partition(string s) {
        vector <vector<string>> result;
        vector <string> temp;
        helper(s,result,temp,0);
        return result;
    }
};