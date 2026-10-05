class Solution {
public:
    int n, m;

    vector<pair<int,int>> gg = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };

    map<pair<int,int>, bool> vis;

    bool check(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    bool dfs(pair<int,int> cord, int k,
             string &word,
             vector<vector<char>> &board) {

        if (k == word.size())
            return true;

        int i = cord.first;
        int j = cord.second;

        if (board[i][j] != word[k])
            return false;
        
        if (vis[cord])
            return false;


        vis[cord] = true;

        if (k == word.size() - 1)
            return true;
            
        for (auto it : gg) {

            int x = i + it.first;
            int y = j + it.second;

            if (check(x, y)) {
                if (dfs({x, y}, k + 1, word, board))
                    return true;
            }
        }
        vis[cord] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == word[0]) {

                    if (dfs({i, j}, 0, word, board))
                        return true;
                }
            }
        }

        return false;
    }
};