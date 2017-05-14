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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while (p2 && p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        ListNode* head2 = p1->next;
        p1->next = NULL;
        p2 = head2->next;
        head2->next = NULL;
        while (p2) 
        {
            p1 = p2->next;
            p2->next = head2;
            head2 = p2;
            p2 = p1;
        }
        p1 = head;
        p2 = head2;
        while(p2)
        {
            ListNode* t1 = p1;
            ListNode* t2 = p2;
            p1 = p1->next;
            t1->next = p2;
            p2 = p2->next;
            t2->next = p1;
        }
    }
};