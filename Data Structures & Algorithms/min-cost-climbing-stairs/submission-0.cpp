class Solution {
public:
    int n;
    vector<int> cost;
    vector<int> dp;
    int solve(int i){
        if(i==n){
            return 0;
        }
        if(i>n){
            return INT_MAX;
        }
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        ans= cost[i]+ min(solve(i+1), solve(i+2));
        return dp[i]=ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        this->cost= cost;
        n=cost.size();
        dp.resize(n+1,-1);
        int ans= min(solve(0), solve(1));
        return ans;
    }
};
