class Solution {
public:
    int cnt;
    vector<vector<int>> vis;
    vector<vector<char>> grid;
    vector<int> row={-1,0,1,0};
    vector<int> col= {0,1,0,-1};
    bool check(int i , int j){
        return i<0 || j<0 || i>=vis.size() || j>=vis[0].size() || grid[i][j]=='0' || vis[i][j];
    }
    void dfs(int i, int j){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int new_i=i+row[k];
            int new_j= j+col[k];
            if(!check(new_i,new_j)){
                dfs(new_i,new_j);
            }
        }
        return;

    }
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        cnt=0;
        this->grid=grid;
        vis.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        return cnt;
    }
};
