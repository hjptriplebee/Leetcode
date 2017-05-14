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
    ListNode* getMid(ListNode* head)
    {
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        while(p2 && p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }
    ListNode* merge(ListNode* head1,ListNode* head2)
    {
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        ListNode* res = new ListNode(0);
        ListNode* res2 = res;
        while(p1 || p2)
        {
            if(!p1)
            {
                res->next = p2;
                break;
            }
            else if(!p2)
            {
                res->next = p1;
                break;
            }
            else if(p1->val < p2->val)
            {
                res->next = p1;
                p1 =p1->next;
            }
            else
            {
                res->next = p2;
                p2 = p2->next;
            }
            res = res->next;
        }
        return res2->next;
    }
    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next) return head;
        ListNode* mid = getMid(head);
        ListNode* head2 = mid->next;
        mid->next = NULL;
        //head = sortList(head);
        //head2 = sortList(head2);
        return merge(sortList(head), sortList(head2));
    }
};