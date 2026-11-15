class Solution {
public:
    string a,b;
    vector<vector<int>> dp;
    int solve(int i,int j){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(a[i]==b[j]){
            ans+= solve(i-1,j-1);
        }
            ans+=solve(i-1,j);
        
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        a=s;
        b=t;
        int n=a.length();
        int m= b.length();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(a.length()-1,b.length()-1);
    }
};
