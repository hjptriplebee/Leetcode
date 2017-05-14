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
    void dfs(vector<int> &res, TreeNode* root, int dep)
    {
        if(!root) return ;
        if(dep == res.size()) res.push_back(root->val);
        if(root->right) dfs(res, root->right, dep + 1);
        if(root->left) dfs(res, root->left, dep + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res, flag;
        dfs(res, root, 0);
        return res;
    }
};