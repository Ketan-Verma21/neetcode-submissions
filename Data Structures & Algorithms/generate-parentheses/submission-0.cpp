class Solution {
public:
    vector<string> ans;
    map<char,int> mp;
    int cnt;
    void solve(string &temp, int n, char prev){
        if(mp['(']==0 && mp[')']==0){
            ans.push_back(temp);  
            return;
        }
        if(n==0)return;
        char c;
        if(prev=='X'){
            c='(';
            temp.push_back(c);
            mp['(']--;
            solve(temp,n-1,'(');
            temp.pop_back();
            mp[c]++;
        }
        else{
            if(mp['(']){
                c='(';
                temp.push_back('(');
                mp['(']--;
                solve(temp,n-1,'(');
                temp.pop_back();
                mp[c]++;
            }
            if(mp[')'] && mp['(']<mp[')']){
                c=')';
                temp.push_back(')');
                mp[')']--;
                solve(temp,n-1,')');
                temp.pop_back();
                mp[c]++;
            }
        }   
        
        return;


    }
    vector<string> generateParenthesis(int n) {
        string temp;
        cnt=n;
        mp['(']=n;
        mp[')']=n;
        solve(temp,2*n,'X');
        return ans;
    }
};
