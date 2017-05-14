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
    TreeNode* dfs(vector<int>& preorder, int ps,int pe,vector<int>& inorder,int is,int ie)
    {
        if(ps>pe ) return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        int pos;
        for(int i=is;;i++)
        if(inorder[i]==preorder[ps])
        {
            pos=i-is;
            break;
        }
        root->left=dfs(preorder,ps+1,ps+pos,inorder,is,is+pos-1);
        root->right=dfs(preorder,ps+pos+1,pe,inorder,is+pos+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};