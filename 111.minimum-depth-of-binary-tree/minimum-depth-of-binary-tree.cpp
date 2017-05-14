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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int a=minDepth(root->left);
        int b=minDepth(root->right);
        if((a==0 && b!=0) || (a!=0 && b==0)) return max(a,b)+1;
        return min(a,b)+1;
    }
};