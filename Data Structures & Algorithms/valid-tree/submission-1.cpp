class Solution {
public:
    vector<int> vis;
    unordered_map<int,vector<int>> adj;
    bool ans=false;
    void dfs(int node, int par){
        vis[node]=1;
        for(int it:adj[node]){
            if(vis[it] && it!=par){
                ans=true;
                return;
            }
            else if(!vis[it] && it!=par){
                dfs(it,node);
            }
        }
        return;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vis.resize(n,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,-1);
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return !ans;
    }
};
