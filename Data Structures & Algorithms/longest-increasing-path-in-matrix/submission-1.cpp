class Solution {
public:
    vector<tuple<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>> dp;
    int n,m;
    vector<vector<int>> matrix;
    bool check(int i,int j,int curr){
        return i>=0 && i<n && j>=0 && j<m && matrix[i][j]>curr;
    }
    int dfs(int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(auto [dx,dy]:dir){
            int new_i= i+dx;
            int new_j= j+dy;
            if(check(new_i,new_j, matrix[i][j])){
                ans= max(ans,1+ dfs(new_i,new_j));
            }
        }
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        this->matrix=matrix;
        int maxi=-1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi=max(maxi,1+dfs(i,j));
            }
        }
        return maxi;
    }
};
