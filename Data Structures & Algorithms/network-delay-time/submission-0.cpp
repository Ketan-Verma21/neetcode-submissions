class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int, vector<pair<int, int>>> adj;

        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int time = top[0];
            int node = top[1];

            if (time > dist[node]) {
                continue;
            }

            for (auto it : adj[node]) {
                int nextNode = it.first;
                int weight = it.second;

                if (dist[nextNode] > time + weight) {
                    dist[nextNode] = time + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int maxi = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }

            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};