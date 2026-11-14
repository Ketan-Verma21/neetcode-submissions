class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<int>> dp;
    int solve(int i ,int can_buy){
        if(i>=n) return 0;
        if(dp[i][can_buy]!=-1) return dp[i][can_buy];
        int ans=0;
        if(can_buy){
            ans=max(-nums[i]+solve(i+1,0), solve(i+1,1));
        }else{
            ans= max(+nums[i]+solve(i+2,1), solve(i+1,0));
        }
        return dp[i][can_buy]=ans;

    }
    int maxProfit(vector<int>& prices) {
        this->nums=prices;
        this->n= prices.size();
        dp.resize(n+1,vector<int>(2,-1));
        return solve(0,1);
    }
};
