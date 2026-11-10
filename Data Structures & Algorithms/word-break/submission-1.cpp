class Solution {
public:
    int n;
    vector<vector<int>> dp;
    map<string, int> mapp;
    string s;
    bool solve(int i, int j){
        if(j==n-1){
            //final check
            return mapp.count(s.substr(i,j-i+1))!=0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        string gg= s.substr(i,j-i+1);
        bool ans=false;
        if(mapp.count(gg)){
            ans= solve(j+1,j+1) || ans;
        }   
        ans= solve(i,j+1)|| ans;
        
        return dp[i][j]=ans? 1:0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        this->s=s;
        for(string it: wordDict){
            mapp[it]=1;
        }
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,0);

    }
};
