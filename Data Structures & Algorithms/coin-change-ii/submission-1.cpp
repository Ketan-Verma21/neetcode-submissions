class Solution {
public:
    int amount;
    vector<int> nums;
    vector<vector<int>> dp;
    int solve(int i, int sum){
        if(sum==amount) return 1;
        if(i<0 || sum>amount) return 0;
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum]= max(solve(i-1,sum+nums[i]), solve(i,sum+nums[i]))+ solve(i-1,sum);
    }   
    int change(int amount, vector<int>& coins) {
        this->amount= amount;
        this->nums=coins;
        int n= coins.size();
        dp.resize(n+1,vector<int>(amount+1,-1));
        return solve(n-1,0);
    }
};
