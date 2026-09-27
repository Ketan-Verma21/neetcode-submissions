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
    bool solve( TreeNode* one, TreeNode* two){
        if(!one && !two){
            return true;
        }
        else if (!one && two || one && !two){
            return false;
        }
        bool left= solve(one->left, two->left);
        bool right= solve(one->right, two->right);
        bool ans=false;
        if(one && two){
            if(one->val==two->val){
                ans=true;
            }
        }
        return left && right && ans;

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};
