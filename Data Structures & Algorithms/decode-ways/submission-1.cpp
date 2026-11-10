class Solution {
public:
    int n;
    string s;
    vector<vector<int>> dp;
    unordered_map<string,char> mapp;
    bool check (string c){
        return mapp.count(c)!=0;
    }
    int solve(int i, int k,string c){
        if(i>=n){
            return 1;
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int ans=0;
        if(k==0){
            // two choices either to take or not
            c.push_back(s[i]);
            if(i<=n-2)ans+= solve(i+1,1,c);
            if(check(c)){
                c.clear();
                ans+=solve(i+1,0,c);
            }
            
        }
        else{
            //only one choice left we have to take it
            c.push_back(s[i]);
            if(check(c)){
                c.clear();
                ans+=(solve(i+1,0,c));
            }
            else{
                return 0;
            }
            
        }
        return dp[i][k]=ans;
    }
    int numDecodings(string s) {
        n= s.length();
        this->s= s;
        int x= 1;
        dp.resize(n+1,vector<int>(3,-1));
        for(char c='A';c<='Z';c++){
            string cc= to_string(x);
            mapp[cc]=c;
            x++;
        }
        return solve(0,0,"");

    }
};
