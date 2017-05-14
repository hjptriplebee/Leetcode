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
    int dfs(TreeNode* root,int &res)
    {
        if(!root) return 0;
        int left=dfs(root->left,res);
        int right=dfs(root->right,res);
        res=max(res,left+right+root->val);
        return root->val+max(left,right)>0?root->val+max(left,right):0;
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        dfs(root,res);
        return res;
    }
};