
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *p=root;
        vector<TreeNode*> s;
        if(!root) return res;
        while(p)
        {
            s.push_back(p);
            p=p->left;
        }
        while(!s.empty())
        {
            p=s[s.size()-1];
            res.push_back(p->val);
            s.pop_back();
            if(p->right)
            {
                p=p->right;
                while(p)
                {
                    s.push_back(p);
                    p=p->left;
                }
            }
        }
        return res;
    }
};