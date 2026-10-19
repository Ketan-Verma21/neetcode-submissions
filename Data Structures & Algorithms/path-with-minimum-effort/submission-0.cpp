
class Solution {
public:
    int n, m;

    bool check(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        vector<int> row = {-1, 0, 1, 0};
        vector<int> col = {0, -1, 0, 1};

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto [effort, pos] = pq.top();
            pq.pop();

            int x = pos.first;
            int y = pos.second;

            if (effort > dist[x][y]) continue;

            if (x == n - 1 && y == m - 1) {
                return effort;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + row[i];
                int ny = y + col[i];

                if (check(nx, ny)) {
                    int newEffort = max(
                        effort,
                        abs(heights[x][y] - heights[nx][ny])
                    );

                    if (newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }

        return 0;
    }
};
