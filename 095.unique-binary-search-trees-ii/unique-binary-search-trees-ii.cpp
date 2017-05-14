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
    vector<TreeNode*> dfs(int l,int r)
    {
        //cout<<l<<" "<<r<<endl;
        if(l==r)
        { 
            TreeNode* p=new TreeNode(l);
            vector<TreeNode*> now(1,p);
            return now;
        }
        vector<TreeNode*> res;
        for(int mid=l;mid<=r;mid++)
        {
            vector<TreeNode*> left,right;
            if(l<=mid-1) 
                left=dfs(l,mid-1);
            else
                left.push_back(NULL);
            if(mid+1<=r) 
                right=dfs(mid+1,r);
            else
                right.push_back(NULL);
            for(int i=0;i<left.size();i++)
            {
                for(int j=0;j<right.size();j++)
                {
                    TreeNode* p=new TreeNode(mid);
                    p->left=left[i];
                    p->right=right[j];
                    res.push_back(p);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res,next;
        res=dfs(1,n);
        return res;
    }
};