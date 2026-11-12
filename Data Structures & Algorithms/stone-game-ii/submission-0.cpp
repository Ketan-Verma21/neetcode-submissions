class Solution {
public:
    vector<int> piles;
    vector<vector<vector<int>>> dp;
    int n;
    vector<int> pre;
    int solve(int i, int person, int k){
        if(i>=n) return 0;
        if(dp[i][person][k]!=-1) return dp[i][person][k];
        int maxi= person==0 ? -1 : 1e9;
        int stone=0;
        for(int j=1;j<=min(2*k, n-i);j++){
            stone+=piles[i+j-1];
            if(person){
                maxi= min(maxi,solve(i+j,!person,max(k,j)));
            }
            else{
                maxi= max(maxi, stone+solve(i+j,!person, max(k,j)));
            }
        }
        return dp[i][person][k]=maxi;
    }
    int stoneGameII(vector<int>& piles) {
        this->n= piles.size();
        this->piles= piles;
        pre.push_back(piles[0]);
        for(int i=1;i<n;i++){
            int x= pre.back();
            pre.push_back(x+piles[i]);
        }
        dp.resize(n+1,vector<vector<int>>(3,vector<int>(n+1,-1)));
        return solve(0,0,1);
    }
};