/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return ; 
        if(root->right)   
        {  
            TreeLinkNode *p=root;
            while(p->next)
            {
                p=p->next;
                if(p->left) 
                {
                    root->right->next=p->left;
                    break;
                }
                else if(p->right)
                {
                    root->right->next=p->right;
                    break;
                }
            }connect(root->right);  
        }
        if(root->left)   
        {  
            if(root->right) 
                root->left->next=root->right;
            else 
            {
                TreeLinkNode *p=root;
                while(p->next)
                {
                    p=p->next;
                    if(p->left) 
                    {
                        root->left->next=p->left;
                        break;
                    }
                    else if(p->right)
                    {
                        root->left->next=p->right;
                        break;
                    }
                }
            }
            connect(root->left); 
        }  
    }
};