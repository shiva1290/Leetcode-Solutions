class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>arr(n+2,0);
        int maxVal=0;
        for(int i=1;i<n+1;i++){
            arr[i]=gain[i-1]+arr[i-1];
            maxVal=max(maxVal,arr[i]);
        }
        return maxVal;
    }
};