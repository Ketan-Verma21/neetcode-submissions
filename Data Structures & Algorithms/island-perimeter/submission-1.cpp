
class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<int>> vis;
    vector<vector<int>> seen;

    vector<int> row = {-1, 0, 1, 0};
    vector<int> col = {0, 1, 0, -1};

    bool check(int i, int j) {
        return i < 0 || i >= grid.size() ||
               j < 0 || j >= grid[0].size() ||
               grid[i][j] == 0;
    }

    void dfs(int i, int j) {
        seen[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int ni = i + row[k];
            int nj = j + col[k];

            if (check(ni, nj)) continue;

            // Count this adjacent land cell
            vis[i][j]++;

            if (!seen[ni][nj]) {
                dfs(ni, nj);
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& input) {
        grid = input;
        int n = grid.size();
        int m = grid[0].size();

        vis.assign(n, vector<int>(m, 0));
        seen.assign(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !seen[i][j]) {
                    dfs(i, j);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans += 4 - vis[i][j];
                }
            }
        }

        return ans;
    }
};
