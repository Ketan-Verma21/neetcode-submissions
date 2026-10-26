class Solution {
public:
    unordered_map<int,vector<int>> adj;
    bool dfs(int node, vector<int> &topo, vector<int> &vis){
        vis[node]=1;
        for(auto it: adj[node]){
            if(vis[it]==1){
                return true;
            }
            else if(vis[it]==0 && dfs(it,topo,vis)){
                return true;
            }
        }
        vis[node]=2;
        topo.push_back(node);
        return false;
    }
    vector<int> topo_sort(unordered_map<int,vector<int>> adj,int k){
        this->adj=adj;
        vector<int> vis(k+1,0);
        vector<int> topo1;
        for(int it=1;it<=k;it++){
            if(!vis[it]){
                bool ans= dfs(it,topo1,vis);
                if(ans) return {};
            }
        }
        reverse(topo1.begin(), topo1.end());
        return topo1;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        unordered_map<int,vector<int>> adj1;
        for(auto it: rowConditions){
            adj1[it[0]].push_back(it[1]);
        }
        vector<int> topo1 = topo_sort(adj1,k);
        if(topo1.empty()) return {};

        unordered_map<int,vector<int>> adj2;
        for(auto it: colConditions){
            adj2[it[0]].push_back(it[1]);
        }
        vector<int> topo2 = topo_sort(adj2,k);
        if(topo2.empty()) return {};

        vector<int> row(k+1), col(k+1,0);
        for(int i=0;i<k;i++){
            row[topo1[i]]=i;
            col[topo2[i]]=i;
        }
        vector<vector<int>> ans(k,vector<int>(k,0));
        for(int i=1;i<=k;i++){
            ans[row[i]][col[i]]=i;
        }
        return ans;
    }
};