
class UnionFind {
public:
    vector<int> par, rank;

    UnionFind(int n) {
        par.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    int findParent(int x) {
        if (par[x] == x) return x;
        return par[x] = findParent(par[x]);
    }

    void _union(int a, int b) {
        a = findParent(a);
        b = findParent(b);

        if (a == b) return;

        if (rank[a] < rank[b]) {
            par[a] = b;
        } else if (rank[a] > rank[b]) {
            par[b] = a;
        } else {
            par[b] = a;
            rank[a]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts
    ) {
        int n = accounts.size();
        UnionFind uf(n);
        map<string, int> mp;

        // Step 1: Union accounts sharing an email.
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (mp.find(email) != mp.end()) {
                    uf._union(i, mp[email]);
                } else {
                    mp[email] = i;
                }
            }
        }

        // Step 2: Group emails by final representative.
        map<int, set<string>> res;

        for (int i = 0; i < n; i++) {
            int root = uf.findParent(i);

            for (int j = 1; j < accounts[i].size(); j++) {
                res[root].insert(accounts[i][j]);
            }
        }

        // Step 3: Build the answer.
        vector<vector<string>> ans;

        for (auto& it : res) {
            int root = it.first;
            vector<string> curr;

            curr.push_back(accounts[root][0]);

            for (const string& email : it.second) {
                curr.push_back(email);
            }

            ans.push_back(curr);
        }

        return ans;
    }
};
