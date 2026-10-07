class Solution {
public:
    int avg_len;
    bool solve(int i, vector<int> &nums, vector<int> &temp,int k){
        if(i==nums.size()){
            for(int x=0;x<k;x++){
                if(temp[x]!=avg_len) return false;
            }
            return true;
        }
        bool ans=false;
        for(int j=0;j<k;j++){
            if(temp[j]+nums[i]<=avg_len){
                temp[j]+=nums[i];
                ans = solve(i+1, nums, temp,k) || ans;
                temp[j]-=nums[i];
            }
            if(temp[j]==0) break;
        }
        return ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum=0;
        for(auto it: nums){
            sum+=it;
        }
        if(sum%k!=0) return false;
        avg_len=sum/k;
        vector<int> temp(k,0);
        sort(nums.rbegin(),nums.rend());
        return solve(0,nums,temp,k);
    }
};