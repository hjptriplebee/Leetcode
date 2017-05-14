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
    void dfs(TreeNode* root, vector<int> &res)  
    {  
          
        if(root->left) dfs(root->left, res);  
        if(root->right) dfs(root->right, res); 
        res.push_back(root->val); 
    }  
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;  
        if(root) dfs(root, res);  
        return res;
    }
};