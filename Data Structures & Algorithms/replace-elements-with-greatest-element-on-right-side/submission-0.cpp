class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans(arr.size(),-1);
        for(int i=arr.size()-2;i>=0;i--){
            ans[i]=max(arr[i+1],ans[i+1]);
        }
        return ans;
    }
};