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
    TreeNode* dfs(TreeNode* root)
    {
        if(!root) return NULL;
        if(!root->left && !root->right) return root;
        TreeNode* q=dfs(root->right);
        TreeNode* p;
        if(root->left)
        {
            p=dfs(root->left);
            p->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        if(q) return q;
        return p;
    }
    void flatten(TreeNode* root) {
        dfs(root);
    }
};