class Solution {
public:
    vector<int> nums;
    vector<vector<int>> dp;
    int solve(int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi;
        for(int k=i;k<=j;k++){
            int coins= nums[k]*nums[i-1]*nums[j+1];
            maxi= max(maxi, coins+solve(i,k-1)+solve(k+1,j));
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& arr) {
        this->nums.clear();
        this->nums.push_back(1);
        this->nums.insert(this->nums.end(), arr.begin(),arr.end());
        this->nums.push_back(1);
        int n=nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(1,nums.size()-2);
    }
};
