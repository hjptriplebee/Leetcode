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
    bool dfs(TreeNode* root,long long minn,long long maxx)
    {
        if(!root) return true;
        if(root->val<=minn || root->val>=maxx) return false;
        if(dfs(root->left,minn,root->val) && dfs(root->right,root->val,maxx)) return true;
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,(long long)INT_MIN-1,(long long)INT_MAX+1);
    }
};