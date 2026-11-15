class Solution {
public:
    vector<vector<int>> dp;
    string a, b, c;

    bool solve(int i, int j) {
        int k = i + j;

        if (i == 0 && j == 0) return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        bool ans = false;

        if (i > 0 && a[i-1] == c[k-1]) {
            ans = solve(i-1, j);
        }

        if (j > 0 && b[j-1] == c[k-1]) {
            ans = ans || solve(i, j-1);
        }

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        a = s1;
        b = s2;
        c = s3;

        dp.assign(a.size()+1, vector<int>(b.size()+1, -1));

        return solve(a.size(), b.size());
    }
};