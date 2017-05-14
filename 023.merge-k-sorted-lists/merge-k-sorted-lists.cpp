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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)   
    {  
        ListNode* p=new ListNode(0);  
        ListNode* result=p;  
        while(l1 && l2)  
        {  
            ListNode* t=new ListNode(0);  
            p->next=t;  
            p=p->next;  
            if(l1->val<l2->val)  
            {  
                p->val=l1->val;  
                l1=l1->next;  
            }  
            else  
            {  
                p->val=l2->val;  
                l2=l2->next;  
            }  
              
        }  
        p->next=l1?l1:l2;  
        return result->next;  
    }  
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        while(lists.size()>1)
        {
            lists.push_back(mergeTwoLists(lists[0],lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        if(lists.size()==0)
            return NULL;
        return *(lists.begin());
    }
};