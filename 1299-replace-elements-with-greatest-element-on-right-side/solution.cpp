class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> answer;
        int maxElement=arr[n-1];
        answer.push_back(-1);
        if(n>1) { answer.push_back(maxElement); }

        for(int i=n-2;i>0;i--){
            if(maxElement<arr[i]){
                answer.push_back(arr[i]);
                maxElement=arr[i];
            }
        else{
            answer.push_back(maxElement);
        }
        }
       
    reverse(answer.begin(),answer.end());
        return answer;
    }
};