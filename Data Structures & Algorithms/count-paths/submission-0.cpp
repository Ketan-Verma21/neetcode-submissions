class Solution {
public:
    vector<tuple<int,int>> dir={{1,0},{0,1}};
    int m,n;
    bool check(int i, int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    vector<vector<int>> dp;
    int dfs(int i, int j){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(auto [di,dj]:dir){
            int new_i= i+di;
            int new_j = j+dj;
            if(check(new_i,new_j)){
                ans+=dfs(new_i,new_j);
            }
        }
        return dp[i][j]=ans;

    }
    int uniquePaths(int m, int n) {
        dp.resize(m+1,vector<int>(n+1,-1));
        this->m=m;
        this->n = n;
        return dfs(0,0);
    }
};
