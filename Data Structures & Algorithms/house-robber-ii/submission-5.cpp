class Solution {
public:
    int last_num;
    int n;
    vector<int> nums;
    vector<int> dp;
    int solve(int i){
        if(i<last_num) return 0;
        if(dp[i]!=-1) return dp[i];
        dp[i]= max(nums[i]+solve(i-2), solve(i-1));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        this->nums=nums;
        this->n= nums.size();
        if(n==1)return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        dp.resize(n+1,-1);
        last_num= 1;
        int ans= solve(n-1);
        fill(dp.begin(), dp.end(),-1);
        last_num= 0;
        ans= max(ans, solve(n-2));
        return ans;
        
    }
};
