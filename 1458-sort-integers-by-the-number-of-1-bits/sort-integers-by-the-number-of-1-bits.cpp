class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> tempArr(32);
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            int a=__builtin_popcount(arr[i]);
            tempArr[a].push_back(arr[i]);
        }
        for(auto & number : tempArr){
            sort(number.begin(),number.end());
        }
         for(auto & number : tempArr){
            for(auto & num : number){
                ans.push_back(num);
            }
        }
        return ans;
    }
};