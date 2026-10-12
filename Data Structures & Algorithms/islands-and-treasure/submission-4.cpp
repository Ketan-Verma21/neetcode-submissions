class Solution {
public:
    int inf;
    int n,m;
    vector<vector<int>> vis;
    vector<int> row={-1,0,1,0};
    vector<int> col={0,-1,0,1};
    bool check(int i, int j,vector<vector<int>> &grid){
        return i<0 || j<0 || i>=n || j>=m || grid[i][j]!=inf || vis[i][j];
    }
    void dfs(int i,int j,vector<vector<int>> &grid,int cnt){
        if(cnt>= grid[i][j] && grid[i][j]!=0){
            return ;
        }
        vis[i][j]=1;
        grid[i][j]=min(grid[i][j],cnt);
        for(int k=0;k<4;k++){
            int new_i=i+row[k];
            int new_j=j+col[k];
            if(!check(new_i,new_j,grid)){
                dfs(new_i,new_j,grid,cnt+1);
            }
        }
        vis[i][j]=0;
        return;
    }
    void bfs(vector<vector<int>>& grid){
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j,0});
                }
            }
        }
        while(!q.empty()){
            vector<int> front= q.front();
            int q_size= q.size();
            q.pop();
            
                for(int j=0;j<4;j++){
                    int new_i=front[0]+row[j];
                    int new_j= front[1]+col[j];
                    if(!check(new_i,new_j,grid)){
                        vis[new_i][new_j]=1;
                        grid[new_i][new_j]=front[2]+1;
                        q.push({new_i,new_j,front[2]+1});
                    }
                }
            
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        inf= INT_MAX;
        vis.resize(n,vector<int>(m,0));
        bfs(grid);
    }
};
