class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, int k, int n, vector<int> &temp){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(i>n || k<0){
            return ;
        }
        temp.push_back(i);
        solve(i+1,k-1,n,temp);
        temp.pop_back();
        solve(i+1,k,n,temp);
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1,k,n,temp);
        return ans;
    }
};