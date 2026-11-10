class Solution {
public:
    vector<int> nums;
    vector<vector<int>> dp;
    int solve(int i, int last){
        if(i<0) return 0;
        if(dp[i][last]!=-1)return dp[i][last];
        int take=0;
        int not_take=0;
        if(nums[last]> nums[i]) take=1+solve(i-1,i);
        not_take= solve(i-1,last);
        return dp[i][last]=max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        dp.resize(n+2,vector<int>(n+2,-1));
        this->nums=nums;
        this->nums.push_back(1e9);
        return solve(n-1,n);
    }
};
