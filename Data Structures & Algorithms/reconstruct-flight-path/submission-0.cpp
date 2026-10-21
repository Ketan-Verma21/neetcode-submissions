class Solution {
public:
    map<string,vector<string>> adj;
    vector<string> ans;
    void dfs(string node){
        while(!adj[node].empty()){
            string last= adj[node].back();
            adj[node].pop_back();
            dfs(last);
        }
        ans.push_back(node);
    }   
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.rbegin(), tickets.rend());
        for(vector<string> it: tickets){
            adj[it[0]].push_back(it[1]);
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

