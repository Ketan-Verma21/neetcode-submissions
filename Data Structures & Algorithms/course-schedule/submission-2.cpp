
class Solution {
public:
    map<int, int> vis;
    map<int, vector<int>> adj;

    void _buildGraph(vector<vector<int>>& prerequisites) {
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
    }

    bool find_loop(int i) {
        vis[i] = 1;

        for (int nei : adj[i]) {
            if (vis[nei] == 1) {
                return true;  // Cycle detected
            }

            if (vis[nei] == 0 && find_loop(nei)) {
                return true;
            }
        }

        vis[i] = 2;
        return false;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {
        vis.clear();
        adj.clear();

        _buildGraph(prerequisites);

        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (find_loop(i)) {
                    return false;
                }
            }
        }

        return true;
    }
};
