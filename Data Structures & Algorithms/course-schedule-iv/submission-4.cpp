class Solution {
public:
    unordered_map<int,set<int>> mp;
    unordered_map<int,vector<int>> adj;
    vector<int> vis;
    void dfs(int node){
        mp[node];
        vis[node]=1;
        for(int it: adj[node]){
            dfs(it);
            mp[node].insert(mp[it].begin(),mp[it].end());
            mp[node].insert(it);
        }
        return;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {  
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));      
        for(vector<int> it:prerequisites){
            int a= it[0];
            int b=it[1];
            adj[a].push_back(b);
            dist[a][b]=1;
        }
        // vis.resize(n,0);
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         dfs(i);
        //     }
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(k!=i && k!=j){
                        if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX){
                            dist[i][j]=min(dist[i][j], INT_MAX);
                        }else{
                            dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                        }
                        
                    }
                }
            }
        }

        vector<bool> ans;
        for(vector<int> it:queries){
            int a = it[0];
            int b= it[1];
            if(dist[a][b]!=INT_MAX){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};