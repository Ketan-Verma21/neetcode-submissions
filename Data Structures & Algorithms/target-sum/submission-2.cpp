class Solution {
public:
    int sum;
    int t;
    vector<int> nums;
    vector<vector<int>> dp;
    int solve(int i, int pos){
        if(i<0){
            return pos==t;
        }
        if(dp[i][pos+sum]!=-1) return dp[i][pos+sum];
        return dp[i][pos+sum]=solve(i-1, pos+nums[i])+ solve(i-1,pos-nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        sum= accumulate(nums.begin(), nums.end(),0);
        this->t= target;
        this->nums=nums;
        int n= nums.size();
        dp.resize(n+1,vector<int>(2*sum+2,-1));
        return solve(n-1,0);
    }
};
