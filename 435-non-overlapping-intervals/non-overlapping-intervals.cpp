class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& Intervals) {
       sort(Intervals.begin(), Intervals.end(),
             [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

    int n=Intervals.size();
    int cnt=1;
    int last=Intervals[0][1];

    for(int i=1;i<n;i++){
            if(Intervals[i][0]>=last){
                cnt++;
                last=Intervals[i][1];
            }
        }
    return n-cnt;
    }
};