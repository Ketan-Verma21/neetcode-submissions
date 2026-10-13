class Solution {
public:
    vector<int> vis;
    map<int,vector<int>> adj;
    vector<int> topo;
    bool solve(int node){
        vis[node]=1;
        for(int it: adj[node]){
            if(vis[it]==1){
                return true;
            }
            else if(vis[it]==0 && solve(it)){
                return true;
            }
        }
        vis[node]=2;
        topo.push_back(node);
        return false;
    }
    void _buildGraph(vector<vector<int>>& pre){
        for(int i=0;i<pre.size();i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        return;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vis.resize(numCourses,0);
        _buildGraph(prerequisites);
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                topo.clear();
                if(solve(i)) return {};
                ans.insert(ans.end(), topo.begin(), topo.end());
            }
        }
        return ans;

    }
};
