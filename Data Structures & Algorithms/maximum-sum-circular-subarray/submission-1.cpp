class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxi=-1e9;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        sum=0;
        int mini=1e9;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mini=min(mini,sum);
            if(sum>0) sum=0;
        }
        int x= accumulate(nums.begin(), nums.end(),0);
        if(x==mini) return maxi;
        maxi= max(maxi, x-mini);
        return maxi;
    }
};