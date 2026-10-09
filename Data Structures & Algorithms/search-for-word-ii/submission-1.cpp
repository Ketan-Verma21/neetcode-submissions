
class TrieNode {
public:
    map<char, TrieNode*> children;
    bool is_last;

    TrieNode() {
        is_last = false;
    }
};

class Solution {
    TrieNode* root;

public:
    vector<string> ans;
    vector<vector<int>> vis;
    int n, m;

    void solve(int i, int j, TrieNode* node, string& word,
               vector<vector<char>>& board) {

        if (i < 0 || i >= n || j < 0 || j >= m ||
            vis[i][j]) {
            return;
        }

        char c = board[i][j];

        auto it = node->children.find(c);

        if (it == node->children.end()) {
            return;
        }

        node = it->second;

        vis[i][j] = 1;
        word.push_back(c);

        if (node->is_last) {
            ans.push_back(word);
            node->is_last=false;
        }

        solve(i + 1, j, node, word, board);
        solve(i - 1, j, node, word, board);
        solve(i, j + 1, node, word, board);
        solve(i, j - 1, node, word, board);

        word.pop_back();
        vis[i][j] = 0;
    }

    void add(const string& word) {
        TrieNode* curr = root;

        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }

            curr = curr->children[c];
        }

        curr->is_last = true;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        if (board.empty() || board[0].empty()) {
            return {};
        }

        root = new TrieNode();
        ans.clear();

        n = board.size();
        m = board[0].size();

        vis.assign(n, vector<int>(m, 0));

        for (const string& w : words) {
            add(w);
        }

        string word;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                solve(i, j, root, word, board);
            }
        }

        return ans;
    }
};