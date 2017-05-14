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
    void dfs(TreeNode* root,int &res,int now)
    {
        if(!root) return ;
        if(!root->left && !root->right) res+=now*10+root->val;
        dfs(root->left,res,now*10+root->val);
        dfs(root->right,res,now*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        int res=0;
        dfs(root,res,0);
        return res;
    }
};