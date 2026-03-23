class Solution {
public:
    bool isValid(int row,int col,int n,int m){
        if(row<0 || row>=n) return false;
        if(col<0 || col>=m) return false;
        return true;
    }
    void bfs(vector<vector<char>>& grid,int r,int c,int n,int m){
        queue<pair<int,int>> q;
        q.push({r,c});
        grid[r][c]='2';
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int row=node.first;
            int col=node.second;
            int delRow[]={-1,1,0,0};
            int delCol[]={0,0,-1,1};
            for(int i=0;i<4;i++){
                int newRow=delRow[i]+row;
                int newCol=delCol[i]+col;
                if(isValid(newRow,newCol,n,m) && grid[newRow][newCol]=='1'){
                    q.push({newRow,newCol});
                    grid[newRow][newCol]='2';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i,j,n,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};