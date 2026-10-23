class Solution {
public:
    vector<int> vis;
    string topo;
    unordered_map<char, vector<char>> adj;

    bool dfs(char c) {
        vis[c - 'a'] = 1;

        for (char it : adj[c]) {
            if (vis[it - 'a'] == 1) return true;

            if (vis[it - 'a'] == 0 && dfs(it)) {
                return true;
            }
        }

        vis[c - 'a'] = 2;
        topo.push_back(c);
        return false;
    }

    string foreignDictionary(vector<string>& words) {
        vis.assign(26, 0);
        topo.clear();
        adj.clear();

        vector<int> exists(26, 0);

        for (string& word : words) {
            for (char c : word) {
                exists[c - 'a'] = 1;
            }
        }

        for (int i = 0; i + 1 < words.size(); i++) {
            string& a = words[i];
            string& b = words[i + 1];

            int x = 0;
            while (x < a.size() && x < b.size() && a[x] == b[x]) {
                x++;
            }

            if (x == b.size() && a.size() > b.size()) {
                return "";
            }

            if (x < a.size() && x < b.size()) {
                adj[a[x]].push_back(b[x]);
            }
        }

        for (int i = 0; i < 26; i++) {
            if (exists[i] && vis[i] == 0) {
                if (dfs('a' + i)) return "";
            }
        }

        reverse(topo.begin(), topo.end());
        return topo;
    }
};