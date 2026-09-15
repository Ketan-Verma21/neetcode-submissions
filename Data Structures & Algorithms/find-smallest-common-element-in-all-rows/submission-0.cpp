class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int,int> mp;
        int ans=-1;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[mat[i][j]]++;
            }
        }
        for(auto it:mp){
            if(it.second==mat.size()){
                return it.first;
            }
        }
        return -1;
    }
};
