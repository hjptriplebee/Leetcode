/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* result=new ListNode(0);
        ListNode* slide=result;
        int cnt=0;
        while(l1!=NULL || l2!=NULL)
        {
            int vala=0,valb=0;
            if(l1!=NULL)
            {
                vala=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                valb=l2->val;
                l2=l2->next;
            }
            
            ListNode* temp=new ListNode((vala+valb+cnt)%10);
            cnt=(vala+valb+cnt)/10;
            slide->next=temp;
            slide=slide->next;
        }
        if(cnt!=0)
        {
            ListNode* temp=new ListNode(cnt);
            slide->next=temp;
        }
        return result->next;
    }
};