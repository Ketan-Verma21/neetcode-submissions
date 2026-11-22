class Solution {
public:
    vector<vector<int>> dp;
    int n, m;
    string s, p;

    bool solve(int i, int j) {
        if (j == m) {
            return i == n;
        }

        if (i > n) return false;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool match = i < n && (s[i] == p[j] || p[j] == '.');

        bool ans = false;

        if (j + 1 < m && p[j + 1] == '*') {
            // Case 1: Ignore the character and *
            // Case 2: Match one character and stay at j
            ans = solve(i, j + 2) ||
                  (match && solve(i + 1, j));
        }
        else {
            // Match current character and move forward
            ans = match && solve(i + 1, j + 1);
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;

        n = s.length();
        m = p.length();

        dp.assign(n + 1, vector<int>(m + 1, -1));

        return solve(0, 0);
    }
};