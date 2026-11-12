class Solution {
public:
    int m,n;
    vector<vector<int>> grid;
    vector<vector<int>> dp;
    vector<tuple<int,int>> dir={{1,0},{0,1}};
    bool check(int i, int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    int dfs(int i, int j){
        if(i==m-1 && j==n-1){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e9;
        for(auto [di,dj]:dir){
            int new_i= i+di;
            int new_j = j+dj;
            if(check(new_i,new_j)){
                ans=min(ans,grid[new_i][new_j]+dfs(new_i,new_j));
            }
        }
        return dp[i][j]=ans;

    }
    int minPathSum(vector<vector<int>>& grid) {
        this->grid=grid;
        
        this->m=grid.size();
        this->n = grid[0].size();
        dp.resize(m+1,vector<int>(n+1,-1));
        return dfs(0,0)+grid[0][0];
    }
};