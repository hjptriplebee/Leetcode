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
    void dfs(TreeNode* root,int now,int sum,vector<vector<int>>& res,vector<int> path)
    {
        now+=root->val;
        path.push_back(root->val);
        if(!root->left && !root->right)
        {
            if(now==sum) res.push_back(path);
            return;
        }
        if(root->left) dfs(root->left,now,sum,res,path);
        if(root->right) dfs(root->right,now,sum,res,path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        if(!root) return res;
        dfs(root,0,sum,res,path);
        return res;
    }
};