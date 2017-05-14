/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        bool flag;
        while(fast->next)
        {
            flag = true;
            fast = fast->next;
            if(fast->next) 
            {
                flag = false;
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast = slow->next;
        slow->next = NULL;
        if(flag) slow = slow->next;
        while(fast)
        {
            ListNode* temp = fast->next;
            fast->next = slow;
            slow = fast;
            fast = temp;
        }
        while(slow && head)
        {
            if(slow->val != head->val) return false;
            slow = slow->next;
            head = head->next;
        }
        if(slow || head) return false;
        return true;
    }
};