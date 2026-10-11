class Solution {
public:
    vector<vector<int>> grid, vis;
    int n,m;
    vector<int> row={-1,0,1,0};
    vector<int> col={0,1,0,-1};
    bool check(int i, int j){
        return i<0 || j<0 || i>=n || j>=m || grid[i][j]==0 || grid[i][j]==2;
    }
    int dfs(int i,int j){
        grid[i][j]=2;
        int cnt=1;
        for(int k=0;k<4;k++){
            int new_i=row[k]+i;
            int new_j=col[k]+j;
            if(!check(new_i,new_j)){
                cnt+=dfs(new_i,new_j);
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        this->grid=grid;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans=max(ans,dfs(i,j));
                }
            }
        }
        return ans;
    }
};
