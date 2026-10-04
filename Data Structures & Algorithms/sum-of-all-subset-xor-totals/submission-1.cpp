class Solution {
public:
     vector<int> nums;

    int solve(int i, int currXor) {
        if (i == nums.size()) {
            return currXor;
        }
        int notTake = solve(i + 1, currXor);
        int take = solve(i + 1, currXor ^ nums[i]);

        return take + notTake;
    }

    int subsetXORSum(vector<int>& nums) {
        this->nums = nums;
        return solve(0, 0);
    }
};