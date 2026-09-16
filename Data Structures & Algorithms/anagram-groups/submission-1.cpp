class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<int,string> mp;
        for(int i=0;i<strs.size();i++){
            mp[i]=strs[i];
        }
        for(auto it:mp){
            string gg= it.second;
            sort(gg.begin(),gg.end());
            mp[it.first]=gg;
        }
        
        map<string,vector<string>> mp2;
        for(auto it:mp){
            mp2[it.second].push_back(strs[it.first]);
        }
        vector<vector<string>> ans;
        for(auto it: mp2){
            ans.push_back(it.second);
        }
        return ans;

    }
};
