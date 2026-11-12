class Solution {
public:
    vector<int> piles;
    vector<vector<int>> dp;
    int n;
    int solve(int i,int j){
        if(j<0 || i<0 || i>j || i>=n || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take_i= piles[i] + min(solve(i+2,j), solve(i+1,j-1));
        int take_j= piles[j] + min(solve(i+1,j-1), solve(i,j-2));
        return dp[i][j]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int sum= accumulate(piles.begin(), piles.end(),0);
        this->n= piles.size();
        this->piles= piles;
        dp.resize(n+1,vector<int>(n+1,-1));
        int ans = solve(0,n-1);
        return ans > (sum-ans) ? true: false;
    }
};