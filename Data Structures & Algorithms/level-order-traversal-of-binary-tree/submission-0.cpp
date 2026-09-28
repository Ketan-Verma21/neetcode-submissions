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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> q;
        int prev=1;
        if(root) q.push({root,1});
        while(!q.empty()){
                vector<int> to_push;
                queue<pair<TreeNode*,int>> new_q;
                while(!q.empty()){
                    pair<TreeNode*, int> top= q.front();
                    q.pop();
                    to_push.push_back(top.first->val);
                    if(top.first->left){
                        new_q.push({top.first->left, top.second+1});
                    }
                    if(top.first->right){
                        new_q.push({top.first->right, top.second+1});
                    }
                }
                ans.push_back(to_push);
                swap(q,new_q);
        }
        return ans;
    }
};
