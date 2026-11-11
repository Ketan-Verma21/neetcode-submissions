class Solution {
public:
    int target;
    vector<int> nums;
    vector<vector<int>> dp;
    bool solve(int i, int sum){
        if(i<0 || sum>target) return false;
        if(sum== target){return true;}
        if(dp[i][sum]!=-1) return dp[i][sum];
        dp[i][sum]= solve(i-1,sum) || solve(i-1,sum+nums[i]);
        return dp[i][sum];
    }
    bool canPartition(vector<int>& nums) {
        this->nums= nums;
        int n= nums.size();
        int sum= accumulate(nums.begin(), nums.end(),0);
        if(sum%2){
            return false;
        }
        dp.resize(n+1,vector<int>(sum+1,-1));
        target= sum/2;
        return solve(n-1,0);
    }
};
