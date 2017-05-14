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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(k<2) return head;
        ListNode* p=head;
        int cnt=0;
        while(p!=NULL)
        {
            cnt++;
            if(cnt==k)
            {
                ListNode* q=head->next;
                head->next=reverseKGroup(p->next,k);
                for(int i=1;i<k;i++)
                {
                    ListNode* temp=q->next;
                    q->next=head;
                    head=q;
                    q=temp;
                }
                break;
            }
            p=p->next;
        }
        return cnt==k?p:head;
    }
};