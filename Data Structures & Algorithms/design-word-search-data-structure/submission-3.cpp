class TrieNode{
    public:
    TrieNode* children[26];
    bool is_last;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        is_last=false;
    }
};
class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root= new TrieNode();
    }
    bool dfs(int i, string &word, TrieNode* root){
        if(i==word.length()-1){
            if(word[i]=='.'){
                bool check=false;
                for(int i=0;i<26;i++){
                    if(root->children[i]){
                        check= root->children[i]->is_last || check;
                    }
                }
                return check;
            }
            else{
                if(root->children[word[i]-'a']){
                    return root->children[word[i]-'a']->is_last;
                }
                return false;
            }
        }
        bool ans=false;
        for(int j=0;j<26;j++){
            if(ans==true) return ans;
            if(root->children[j]){
            if(word[i]=='.'){
                    ans= dfs(i+1,word,root->children[j]) || ans;
            }
            else{
                ans= (word[i]-'a')== j ? dfs(i+1,word,root->children[j]):false;
            }}
        }
        return ans;
    }
    void addWord(string word) {
        TrieNode* curr=root;
        for(char c:word){
            int i=c-'a';
            if(curr->children[i]==nullptr){
                curr->children[i]=new TrieNode();
            }
            curr= curr->children[i];
        }
        curr->is_last=true;
        return;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        return dfs(0,word,curr);
    }
};
