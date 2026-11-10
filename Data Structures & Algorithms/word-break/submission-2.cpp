class Trie{
    public:
    Trie* children[26];
    bool is_last;
    Trie(){
        is_last=false;
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};
class Solution {
    Trie* root;
public:
    int n;
    vector<vector<int>> dp;
    string s;
    bool solve(int i, int j){
        if(j==n-1){
            //final check
            return find(s.substr(i,j-i+1));
        }
        if(dp[i][j]!=-1) return dp[i][j];
        string gg= s.substr(i,j-i+1);
        bool ans=false;
        if(find(gg)){
            ans= solve(j+1,j+1) || ans;
        }   
        ans= solve(i,j+1)|| ans;
        
        return dp[i][j]=ans? 1:0;
    }
    void insert(string word){
        Trie* temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->children[word[i]-'a']==nullptr){
                temp->children[word[i]-'a']= new Trie();
            }
            temp= temp->children[word[i]-'a'];
        }
        temp->is_last=true;
    }
    bool find(string word){
        Trie* temp=root;
        for(int i=0;i<word.size();i++){
            if(temp->children[word[i]-'a']==nullptr){
                return false;
            }
            temp=temp->children[word[i]-'a'];
        }
        return temp->is_last;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        root= new Trie();
        for(string it: wordDict){
            insert(it);
        }
        n=s.length();
        this->s=s;
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,0);

    }
};
