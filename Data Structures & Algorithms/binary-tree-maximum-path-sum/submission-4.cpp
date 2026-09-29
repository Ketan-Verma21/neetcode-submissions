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
    int ans;
    int solve(TreeNode* root){
        if(!root){
            return -1e9;
        }
        int left= solve(root->left);
        int right= solve(root->right);
        this->ans= max({ans,left,right, left+root->val ,left+right+root->val,right+root->val,root->val});
        
        return max({left+root->val, right+root->val,root->val});

    }
    int maxPathSum(TreeNode* root) {
        this->ans=-1e9;
        solve(root);
        return this->ans;
    }
};
