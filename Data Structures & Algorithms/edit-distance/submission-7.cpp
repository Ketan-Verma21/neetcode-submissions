class Solution {
public:
    string a,b;
    vector<vector<int>> dp;
    int solve(int i,int j){
        if(j<0 && i>=0){
            return i+1;
        }
        if(i<0 && j>=0){
            return j+1;
        }
        if(i<0 && j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];         
        int ans=0;
        if(a[i]==b[j]){
            ans=solve(i-1,j-1);
        }
        else{
            ans= 1+min({(solve(i,j-1)), solve(i-1,j), solve(i-1,j-1)});
        }
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        a=word1;
        b=word2;
        int n=a.length();
        int m= b.length();
        if(n==0) return m;
        if(m==0) return n;
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1);
    }
};
