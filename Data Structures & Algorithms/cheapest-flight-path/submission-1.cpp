class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int, vector<vector<int>>> adj;

        for (auto &flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // cost[node][edgesUsed]
        vector<vector<int>> cost(n, vector<int>(k + 2, INT_MAX));

        // {cost, edgesUsed, node}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        cost[src][0] = 0;
        pq.push({0, 0, src});

        while (!pq.empty()) {
            int cst = pq.top()[0];
            int edges = pq.top()[1];
            int node = pq.top()[2];
            pq.pop();

            if (node == dst) return cst;

            if (edges == k + 1) continue;

            if (cst != cost[node][edges]) continue;

            for (auto &it : adj[node]) {
                int nextNode = it[0];
                int price = it[1];

                if (cost[nextNode][edges + 1] > cst + price) {
                    cost[nextNode][edges + 1] = cst + price;
                    pq.push({cst + price, edges + 1, nextNode});
                }
            }
        }

        return -1;
    }
};