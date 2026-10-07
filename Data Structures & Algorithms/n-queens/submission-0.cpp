class Solution {
public:
    map<int,int> row, col, diag_a, diag_b;
    vector<vector<string>> ans;
    bool check(int i, int j){
        if(row[i] ||  col[j] || diag_a[i-j] || diag_b[j+i]){
            return false;
        }
        return true;
    }
    void set(int i, int j, int k){
        row[i]=k;
        col[j]=k;
        diag_a[i-j]=k;
        diag_b[j+i]=k;
    }
    void solve(int i, vector<string> &temp,int n){
        if(i==n){
            ans.push_back(temp);
            return ;
        }
        for(int j=0;j<n;j++){
            if(check(i,j)){
                set(i,j,1);
                temp[i][j]='Q';
                solve(i+1,temp,n);
                temp[i][j]='.';
                set(i,j,0);
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i].push_back('.');
            }
        }
        solve(0,temp,n);
        return ans;
    }
};
