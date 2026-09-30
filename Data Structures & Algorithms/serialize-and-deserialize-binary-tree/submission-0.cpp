/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    void dfs(TreeNode* root, vector<string> &v){
        if(!root){
            v.push_back("N");
            return;
        }
        v.push_back(to_string(root->val));
        dfs(root->left,v);
        dfs(root->right,v);
        return;
    }
    vector<string> split(string s){
        int l=0;
        vector<string> ans;
        for(int r=1;r<s.length();r++){
            if(s[r]==','){
                // cout<<l<<" "<<r<<"  ";
                ans.push_back(s.substr(l,r-l));
                // cout<<s.substr(l,r-l)<<"   ";
                l=r+1;
            }
            else{
                continue;
            }
        }
        ans.push_back("N");
        return ans;
    }   
    string serialize(TreeNode* root) {
        vector<string> v;
        dfs(root,v);
        string s;
        for(auto it:v){
            for(auto it2:it){
                s.push_back(it2);
            }
            s.push_back(',');
        }
        s.pop_back();
        return s;
        
    }
    TreeNode* solve(int &i){
        if(i>= v.size() || v[i]=="N"){
            i++;
            return nullptr;
        }
        TreeNode* n= new TreeNode(std::stoi(v[i]));
        i++;
        n->left=solve(i);
       
        n->right=solve(i);
        return n;
    }
    vector<string> v;
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        vector<string> v;
        v=split(data);
        this->v=v;
        int l=0;
        TreeNode* temp=solve(l);
        
        return temp;
    }
};
