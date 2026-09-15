class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n=arrays.size();
        int maxi=arrays[0][arrays[0].size()-1], mini=arrays[0][0];
        int ans=0;
        for(int i=1;i<n;i++){
            int m=arrays[i].size();
            ans=max({(maxi-arrays[i][0]),(arrays[i][m-1]-mini),ans});
            maxi=max(maxi,arrays[i][m-1]);
            mini=min(mini,arrays[i][0]);
        }
        return ans;



    }
};
