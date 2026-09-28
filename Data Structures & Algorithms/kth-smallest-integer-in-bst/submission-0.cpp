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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        s.push(root);
        map<TreeNode*, bool> vis;
        while(!s.empty()){
            TreeNode* top=s.top();
            if(top->left && !vis[top->left]){
                s.push(top->left);
            }
            else {
                vis[top]=1;
                s.pop();
                k--;
                if(top->right) s.push(top->right);
            }
            if(k==0){
                return top->val;
            }
        }
        return -1;
    }
};
