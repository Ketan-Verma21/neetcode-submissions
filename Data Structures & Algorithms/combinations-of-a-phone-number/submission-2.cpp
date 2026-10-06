class Solution {
public:
    vector<string> ans;
    map<int,vector<int>> mp;
    void solve(int i, string &digits, string &temp){
        if(temp.length()==digits.length()){
            ans.push_back(temp);
            return;
        }
        int num= std::stoi(digits.substr(i,1));
        for(auto it:mp[num]){
            temp.push_back('a'+it);
            solve(i+1,digits,temp);
            temp.pop_back();
        }
        return;

    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ans;
        mp[2]={0,1,2};
        for(int i=3;i<=9;i++){
            int lim= i==8? 4: 3;
            for(int j=0;j<3;j++){
                mp[i].push_back(mp[i-1][j]+lim);
            }
            if(i==7 || i==9){
                int last= mp[i].back();
                mp[i].push_back(last+1);
            }
        }
        string temp;
        solve(0,digits,temp);
        return ans;

    }
};
