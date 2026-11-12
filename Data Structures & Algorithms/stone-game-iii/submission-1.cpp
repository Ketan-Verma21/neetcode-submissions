class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<int>> dp;
    int solve(int i, int player){
        if(i>=n){
            return 0;
        }
        if(dp[i][player]!=-1) return dp[i][player];
        int maxi= !player? -1e9: 1e9;
        int stone=0;
        for(int j=1;j<=min(3,n-i);j++){
            stone+=nums[i+j-1];
            if(player){
                maxi=min(maxi,solve(i+j,!player));
            }
            else{
                maxi= max(maxi, stone+solve(i+j,!player));
            }
        }
        return dp[i][player]=maxi;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int sum= accumulate(stoneValue.begin(), stoneValue.end(),0);
        this->n= stoneValue.size();
        this->nums= stoneValue;
        dp.resize(n+1,vector<int>(3,-1));
        int a= solve(0,0);
        int b= sum-a;
        if(a==b){
            return "Tie";
        }
        else if(a>b){
            return "Alice";
        }else{
            return "Bob";
        }
    }
};