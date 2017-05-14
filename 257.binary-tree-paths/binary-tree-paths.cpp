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
    void dfs(vector<string> &res, TreeNode* root, string now)
    {
        now += to_string(root->val);
        if(root->left || root->right)
        {
            now += "->";
            if(root->left) dfs(res, root->left, now);
            if(root->right) dfs(res, root->right, now);
        }
        else
            res.push_back(now);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        dfs(res, root, "");
        return res;
    }
};