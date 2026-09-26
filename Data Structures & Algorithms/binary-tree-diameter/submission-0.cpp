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
    int res;
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int left= solve(root->left);
        int right= solve(root->right);
        this->res= max(this->res, left+right);
        return 1+max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        this->res=0;
        solve(root);
        return this->res;
    }
};
