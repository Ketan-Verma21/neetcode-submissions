class Solution {
public:
    vector<int> nums;
    int n;
    vector<int> dp;
    int solve(int i){
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        
        dp[i]= max(nums[i]+solve(i-2), solve(i-1));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        this->nums=nums;
        n= nums.size();
        dp.resize(n+1,-1);
        return max(solve(n-1), solve(n-2));
    }
};
