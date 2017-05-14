/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void dfs(string &path, TreeNode* root)
    {
        if(!root)
        {
            path += "#";
            return ;
        }
        path += to_string(root->val) + "#";
        dfs(path, root->left);
        dfs(path, root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs(res, root);
        return res;
    }
    
    TreeNode* dfs2(string &data)
    {
        //if(data.empty()) return ;
        int pos = data.find("#");
        if(!pos)
        {
            data = data.substr(pos + 1);
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(data.substr(0, pos)));
        data = data.substr(pos + 1);
        root->left = dfs2(data);
        root->right = dfs2(data);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string data2 = data;
        return dfs2(data2);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));