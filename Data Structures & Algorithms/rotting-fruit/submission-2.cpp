class Solution {
public:
    int n,m;
    vector<int> row={-1,0,1,0};
    vector<int> col={0,-1,0,1};
    bool check(int i,int j, vector<vector<int>>& grid){
        return i<0 || i>=n || j<0 || j>=m || grid[i][j]!=1;
    }
    int bfs(vector<vector<int>>& grid){
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            vector<int> front= q.front();
            q.pop();
            ans=front[2];
            for(int i=0;i<4;i++){
                int new_i= front[0]+row[i];
                int new_j= front[1]+col[i];
                if(!check(new_i,new_j,grid)){
                    grid[new_i][new_j]=2;
                    q.push({new_i,new_j,front[2]+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        return bfs(grid);
    }
};
