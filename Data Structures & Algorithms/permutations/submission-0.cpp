class Solution {
public:
    map<int,int> mp;
    vector<vector<int>> ans;
    void solve(int i, vector<int> &nums, vector<int> &temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        if(i==nums.size()){
            return;
        }
        
        for(auto it: mp){
            if(!mp[it.first]){
                temp.push_back(nums[it.first]);
                mp[it.first]=1;
                solve(i+1,nums,temp);
                temp.pop_back();
                mp[it.first]=0;
            }
        }
        
                
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        mp.clear();
        ans.clear();
        for(int i=0;i<nums.size();i++){
            mp[i]=0;
        }
        vector<int> temp;
        solve(0,nums,temp);
        return ans;
    }
};
