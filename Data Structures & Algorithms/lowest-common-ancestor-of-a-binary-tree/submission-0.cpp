/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return nullptr;
        }
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        TreeNode* left= solve(root->left, p, q);
        TreeNode* right= solve(root->right,p,q);
        if(left && right){
            return root;
        }
        else{
            if(left){
                return left;
            }
            else if(right){
                return right;
            }
            else{
                return nullptr;
            }
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};