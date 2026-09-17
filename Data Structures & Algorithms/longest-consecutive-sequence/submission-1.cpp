class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        // vector<int> gg(n,1);
        for(int i=0;i<n;i++){
            mp[nums[i]]=1;
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            if(!mp[nums[i]-1]){
                int cnt=1;
                while(mp[nums[i]+cnt]){
                    cnt++;
                }
                maxi=max(cnt,maxi);
            }
        }
        return maxi;
        
    }
};
