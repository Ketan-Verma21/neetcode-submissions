class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int> nums, int sum, vector<int> &temp){
        if(sum==0){
            ans.push_back(temp);
            return;
        }
        if(i==nums.size() || sum<0){
            return;
        }
        
        temp.push_back(nums[i]);
        solve(i, nums, sum-nums[i], temp);
        temp.pop_back();
        solve(i+1, nums, sum, temp);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        solve(0,nums,target,temp);
        return ans;
    }
};
