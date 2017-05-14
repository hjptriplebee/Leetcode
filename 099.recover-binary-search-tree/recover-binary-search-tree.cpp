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
    void dfs(TreeNode* root,vector<TreeNode*> &path)
    {
        if(!root) return ;
        dfs(root->left,path);
        path.push_back(root);
        dfs(root->right,path);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> path;
        dfs(root,path);
        int st=0,en=path.size()-1;
        while(st<en)
        {
            if(path[st]->val<path[st+1]->val) 
                st++;
            else if(path[en]->val>path[en-1]->val) 
                en--;
            else
            {
                swap(path[en]->val,path[st]->val);
                return ;
            }
        }
        
    }
};