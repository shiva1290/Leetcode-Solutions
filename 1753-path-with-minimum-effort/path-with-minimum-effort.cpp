#define P pair<int, pair<int, int>>
class Solution {
public:
    bool isValid(int r, int c, int n, int m) {
        if (r < 0 || r >= n)
            return false;
        if (c < 0 || c >= m)
            return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        int deltaRow[]={1,0,-1,0};
        int deltaCol[]={0,1,0,-1};
        vector<vector<int>> maxDiff(n,vector<int>(m,1e9));
        priority_queue<P,vector<P>,greater<P>> pq;
        maxDiff[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            int diff=node.first;
            int row=node.second.first;
            int col=node.second.second;
            if(row==n-1 && col==m-1) return diff;
            for(int i=0;i<4;i++){
                int newRow=row+deltaRow[i];
                int newCol=col+deltaCol[i];
                if(isValid(newRow,newCol,n,m)){
                    int currDiff=abs(heights[newRow][newCol]-heights[row][col]);
                    int maxCurrent=max(currDiff,diff);
                    if(maxCurrent<maxDiff[newRow][newCol]){
                        maxDiff[newRow][newCol]=maxCurrent;
                        pq.push({maxCurrent,{newRow,newCol}});
                    }
                }
            }
        }
        return -1;
    }
};