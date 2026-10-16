class Solution {
public:
    map<int,vector<int>> adj;
    vector<int> vis;
    void dfs(int node){
        vis[node]=1;
        for(int it:adj[node]){
            if(!vis[it]){
                dfs(it);
            }
        }
        return ;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vis.resize(n,0);
        for(vector<int> it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i);
            }
        }
        return cnt;
    }
};
