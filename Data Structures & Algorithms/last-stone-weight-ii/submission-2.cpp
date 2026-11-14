class Solution {
public:
    int target;
    vector<vector<int>> dp;
    vector<int> nums;
    int total;
    int solve(int i, int sum){
        if(sum>= target || i<0){
            return abs(sum-(total-sum));
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum]= min(solve(i-1,sum), solve(i-1,sum+nums[i]));
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n= stones.size();
        this->nums= stones;
        int sum= accumulate(stones.begin(), stones.end(),0);
        total=sum;
        target= sum/2;
        dp.resize(n+1,vector<int>(sum+1,-1));
        return solve(n-1,0);
        
    }
};