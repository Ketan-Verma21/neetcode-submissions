class Solution {
public:
    vector<int> nums;
    vector<int> dp;

    int solve(int sum) {
        if(sum == 0) return 1;

        if(dp[sum] != -1) return dp[sum];

        int ans = 0;

        for(int x : nums) {
            if(sum >= x) {
                ans += solve(sum - x);
            }
        }

        return dp[sum] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        this->nums = nums;
        dp.assign(target + 1, -1);

        return solve(target);
    }
};