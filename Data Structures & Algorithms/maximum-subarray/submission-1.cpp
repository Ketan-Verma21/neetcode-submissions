class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadane algo
        int sum=0;
        int maxi=-1e9;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }   
        return maxi;
    }
};
