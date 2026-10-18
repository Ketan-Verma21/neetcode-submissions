
class Solution {
public:
    map<string, vector<pair<string, double>>> adj;

    double bfs(string start, string target) {
        if (!adj.count(start) || !adj.count(target))
            return -1.0;

        queue<pair<string, double>> q;
        set<string> visited;

        q.push({start, 1.0});
        visited.insert(start);

        while (!q.empty()) {
            auto [node, product] = q.front();
            q.pop();

            if (node == target)
                return product;

            for (auto [next, value] : adj[node]) {
                if (visited.insert(next).second) {
                    q.push({next, product * value});
                }
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        adj.clear();

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];

            adj[a].push_back({b, values[i]});
            adj[b].push_back({a, 1.0 / values[i]});
        }

        vector<double> result;

        for (auto& query : queries) {
            result.push_back(bfs(query[0], query[1]));
        }

        return result;
    }
};
