class Solution {
public:
    vector<vector<int>> dp;
    string a,b;
    int solve(int i, int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(a[i]==b[j]){
            ans=1+solve(i-1,j-1);
        }
        else{
            ans= max(solve(i-1,j),solve(i,j-1));
        }
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.length();
        int m= text2.length();
        dp.resize(n+1,vector<int>(m+1,-1));
        this->a= text1;
        this->b= text2;
        return solve(n-1,m-1);
    }
};
