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
    int dfs(TreeNode* root,bool& res)
    {
        if(!root) return 0;
        int a=dfs(root->left,res)+1;
        int b=dfs(root->right,res)+1;
        if(abs(a-b)>1) res=false;
        return max(a,b);
    }
    bool isBalanced(TreeNode* root) {
        bool res=true;
        dfs(root,res);
        return res;
    }
};