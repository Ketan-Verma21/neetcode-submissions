class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
            if(!mp[target-nums[i]].empty()){
                vector<int> ans;
                for(int j=0;j<mp[target-nums[i]].size();j++){
                    if(i!=mp[target-nums[i]][j]){
                        ans.push_back(mp[target-nums[i]][j]);
                        ans.push_back(i);
                        return ans;
                    }
                }
            }
        }
        vector<int> ans;
        return ans;
    }
};
