/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map <RandomListNode*, RandomListNode*> mp;
        if(!head) return NULL;
        RandomListNode* p = head;
        RandomListNode* res = new RandomListNode(head->label);
        RandomListNode* q = res;
        mp[p] = q;
        while(p->next)
        {
            p = p->next;
            q->next = new RandomListNode(p->label);
            q = q->next;
            mp[p] = q;
        }
        p = head;
        q = res;
        while(p)
        {
            q->random = mp[p->random];
            p = p->next;
            q = q->next;
        }
        return res;
    }
};