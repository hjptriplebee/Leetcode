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
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        return 1 + dfs(root->left);
    }
    int countNodes(TreeNode* root) {
        int h = dfs(root), res = 0;
        while(root)
        {
            if(dfs(root->right) == h - 1)
            {
                res += 1 << (h - 1);
                root = root ->right;
            }
            else
            {
                res += 1 << (h - 2);
                root = root ->left;
            }
            h--;
        }
        return res;
    }
};