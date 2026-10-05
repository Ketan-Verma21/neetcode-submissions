class Solution {
public:
    string s;
    vector<vector<string>> ans;
    bool check(int i, int j){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    void solve(int i, int j, vector<string> &temp){
        if(i>=s.length()){
            ans.push_back(temp);
            return;
        }
        for(int k=i;k<=j;k++){
            if(check(i,k)){
                temp.push_back(s.substr(i,k-i+1));
                solve(k+1,j,temp);
                temp.pop_back();
            }
        }
        return;

    }
    vector<vector<string>> partition(string s) {
        this->s=s;
        vector<string> temp;
        solve(0,s.length()-1,temp);
        return ans;
    }
};
