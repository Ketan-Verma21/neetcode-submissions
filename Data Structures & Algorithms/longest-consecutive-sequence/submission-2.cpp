class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(!mp[nums[i]]){
                mp[nums[i]]=mp[nums[i]-1]+mp[nums[i]+1]+1;
                mp[nums[i]-mp[nums[i]-1]]=mp[nums[i]];
                mp[nums[i]+mp[nums[i]+1]]=mp[nums[i]];
                maxi=max(maxi,mp[nums[i]]);
            }
        }
        return maxi;
        
    }
};
