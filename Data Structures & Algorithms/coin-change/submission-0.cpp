class Solution {
public:
    vector<vector<int>> dp;
    vector<int> coins;

    int solve(int i, int sum) {
        if (sum == 0) return 0;

        if (i < 0 || sum < 0) return INT_MAX;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        int take = INT_MAX;
        int notTake = solve(i - 1, sum);

        // Take current coin (unlimited supply)
        int temp = solve(i, sum - coins[i]);

        if (temp != INT_MAX)
            take = 1 + temp;

        return dp[i][sum] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        this->coins = coins;

        dp.assign(n, vector<int>(amount + 1, -1));

        int ans = solve(n - 1, amount);

        return ans == INT_MAX ? -1 : ans;
    }
};