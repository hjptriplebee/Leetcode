/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* dfs(vector<int>& nums,int l,int r)  
    {  
        if(l>r) return NULL;  
        int mid=(l+r)>>1;  
        TreeNode* p=new TreeNode(nums[mid]);  
        p->left=dfs(nums,l,mid-1);  
        p->right=dfs(nums,mid+1,r);  
        return p;  
    }  
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head) 
        {
            nums.push_back(head->val);
            head=head->next;
        }
        return dfs(nums,0,nums.size()-1);  
    }
};