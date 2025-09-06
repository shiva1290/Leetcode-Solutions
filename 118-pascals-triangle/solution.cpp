class Solution {
public:
 vector <int> getrow(int row){
  long long ans=1;
        vector <int> answer;
        answer.push_back(1); 
        for(int i = 1; i <= row; i++){
            ans = ans * (row - i + 1); 
            ans = ans/i;
            answer.push_back(ans);
        }
        return answer;
    }


    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer2;
        for(int i=0;i<numRows;i++){
            vector<int> temp=getrow(i);
            answer2.push_back(temp);
        }
        return answer2;
    }
};