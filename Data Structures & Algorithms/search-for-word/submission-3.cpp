class Solution {
public:
    int n, m;

    vector<pair<int,int>> gg = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };

    bool check(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    bool dfs(int i, int j, int k,
             string &word,
             vector<vector<char>> &board) {

        // Out of bounds
        if (!check(i, j))
            return false;

        // Character doesn't match
        if (board[i][j] != word[k])
            return false;

        // We found the complete word
        if (k == word.size() - 1)
            return true;

        // Mark visited
        char temp = board[i][j];
        board[i][j] = '#';

        for (int d = 0; d < 4; d++) {

            int x = i + gg[d].first;
            int y = j + gg[d].second;

            if (dfs(x, y, k + 1, word, board))
                return true;
        }

        // Backtrack
        board[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        n = board.size();
        m = board[0].size();

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {

                if (dfs(r, c, 0, word, board))
                    return true;
            }
        }

        return false;
    }
};