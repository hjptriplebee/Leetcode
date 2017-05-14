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
    bool dfs(TreeNode* root,int now,int sum)
    {
        now+=root->val;
        if(!root->left && !root->right) return now == sum;
        bool l=false,r=false;
        if(root->left) l=dfs(root->left,now,sum);
        if(root->right) r=dfs(root->right,now,sum);
        return l || r;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        return dfs(root,0,sum);
    }
};