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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* p=head;
        if(!p) return p;
        int cnt=1,cnt2=1;
        while(p->next!=NULL)
        {
            cnt++;
            p=p->next;
        }
        k%=cnt;
        if(k==0) return head;
        cnt-=k;
        ListNode* q=head;
        while(cnt2!=cnt)
        {
            cnt2++;
            q=q->next;
        }
        p->next=head;
        head=q->next;
        q->next=NULL;
        return head;
    }
};