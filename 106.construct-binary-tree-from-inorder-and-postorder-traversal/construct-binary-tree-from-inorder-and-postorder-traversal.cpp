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
        TreeNode* root=new TreeNode(preorder[pe]);  
        int pos;  
        for(int i=is;;i++)  
        if(inorder[i]==preorder[pe])  
        {  
            pos=ie-i;  
            break;  
        }  
        root->left=dfs(preorder,ps,pe-pos-1,inorder,is,ie-pos-1);  
        root->right=dfs(preorder,pe-pos,pe-1,inorder,ie-pos+1,ie);  
        return root;  
    }  
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(postorder,0,inorder.size()-1,inorder,0,inorder.size()-1);
    }
};