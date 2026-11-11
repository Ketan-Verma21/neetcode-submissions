class Solution {
public:
    vector<int> dp;
    vector<int> nums;
    int solve(int n){
        if(n==0) return 1;
        if(n<0) return 1e9;
        if(dp[n]!=-1) return dp[n];
        int ans=1e9;
        for(int i=0;i<100;i++){
            int gg= solve(n-nums[i]);
            if(gg!=1e9){
                gg++;
            }
            ans=min(gg, ans);
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        for(int i=1;i<101;i++){
            nums.push_back(i*i);
        }
        dp.resize(n+1,-1);
        return solve(n)-1;
    }
};