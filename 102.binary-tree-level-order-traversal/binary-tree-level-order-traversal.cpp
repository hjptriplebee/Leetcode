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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> temp;
        queue<TreeNode*> q,q2;
        q.push(root);
        while(!q.empty() || !q2.empty())
        {
            if(q.empty())
            {
                swap(q,q2);
                res.push_back(temp);
                temp.clear();
            }
            TreeNode* first=q.front();
            q.pop();
            if(!first)continue;
            temp.push_back(first->val);
            q2.push(first->left);
            q2.push(first->right);
        }
        return res;
    }
};