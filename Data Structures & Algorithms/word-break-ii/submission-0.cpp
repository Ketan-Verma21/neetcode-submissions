class Solution {
public:
    map<string,int> mp;
    vector<string> ans;
    void solve(int i, int j, string &s, string &temp){
        if(i==s.length()){
            string to_push=temp;
            to_push.pop_back();
            ans.push_back(to_push);
            return;
        }
        for(int k=i;k<=j;k++){
            string gg= s.substr(i,k-i+1);
            if(mp[gg]){
                string mm= temp;
                gg.push_back(' ');
                temp.append(gg);
                solve(k+1,j,s,temp);
                temp=mm;
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto it: wordDict){
            mp[it]=1;
        }
        string temp;
        solve(0,s.length()-1,s,temp);
        return ans;
    }
};