class Solution {
public:
    vector<int> dp;
    int solve(int n){
        if(dp[n]!=-1)return dp[n];
        dp[n]= solve(n-1)+solve(n-2)+solve(n-3);
        return dp[n];
    }
    int tribonacci(int n) {
        int m= n<3? 3:n;
        dp.resize(m+1,-1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        if(n<3){
            return dp[n];
        }
        return solve(n);
    }
};