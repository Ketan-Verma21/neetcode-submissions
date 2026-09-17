class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>> gg;
        for(int i=0;i<n;i++){
            if(nums[i]>0)break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int r=n-1;
            int l= i+1;
            while(l<r){
                if(nums[l]+nums[r]+nums[i]>0){
                    r--;
                }
                else if(nums[l]+nums[r]+nums[i]==0){
                    gg.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else{
                    l++;
                }
            }

        }
        vector<vector<int>> ans;
        for(auto it: gg){
            ans.push_back(it);
        }
        return ans;
    }

};
