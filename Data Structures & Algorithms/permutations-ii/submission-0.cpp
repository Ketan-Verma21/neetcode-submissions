class Solution {
public:
    vector<vector<int>> ans;
    map<int,int> mp; 
    int n;
    void solve(vector<int> &temp){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(auto it:mp){
            if(mp[it.first]){
                temp.push_back(it.first);
                mp[it.first]--;
                solve(temp);
                temp.pop_back();
                mp[it.first]++;
            }

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        n=nums.size();
        vector<int> temp;
        solve(temp);
        return ans;
    }
};