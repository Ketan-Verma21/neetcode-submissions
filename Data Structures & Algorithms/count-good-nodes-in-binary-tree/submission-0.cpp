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

class Solution {
public:
    int goodNodes(TreeNode* root) {
       queue<pair<TreeNode*,TreeNode*>> q;
       TreeNode temp(-101);
       TreeNode* gg=&temp;
       if(root) q.push({root, gg});
       int ans=0;
       while(!q.empty()){
        pair<TreeNode*, TreeNode*> top= q.front();
        q.pop();
        TreeNode* prev;
        if(top.first->val >= top.second->val){
            ans++;
            prev=top.first;
           
        }else{
            prev=top.second;
        }
        if(top.first->left){
            q.push({top.first->left,prev});
        }
        if(top.first->right){
            q.push({top.first->right,prev});
        }

       } 
       return ans;
    }
};
