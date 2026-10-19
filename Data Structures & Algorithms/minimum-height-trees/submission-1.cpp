
class Solution {
public:
    map<int, vector<int>> adj;
    vector<int> path;

    pair<int, int> dfs(int node, int par) {
        int final_node = node, dist = 0;

        for (int it : adj[node]) {
            if (it != par) {
                auto res = dfs(it, node);

                if (1 + res.second > dist) {
                    final_node = res.first;
                    dist = 1 + res.second;
                }
            }
        }

        return {final_node, dist};
    }

    bool findPath(int node, int tar, int par) {
        if (node == tar) {
            path.push_back(node);
            return true;
        }

        for (int it : adj[node]) {
            if (it != par) {
                if (findPath(it, tar, node)) {
                    path.push_back(node);
                    return true;
                }
            }
        }

        return false;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        adj.clear();
        path.clear();

        if (n == 1) return {0};

        for (auto& it : edges) {
            int a = it[0], b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        auto a = dfs(0, -1);
        auto b = dfs(a.first, -1);

        findPath(a.first, b.first, -1);

        int sz = path.size();

        if (sz % 2 == 1) {
            return {path[sz / 2]};
        }

        return {path[sz / 2], path[sz / 2 - 1]};
    }
};
