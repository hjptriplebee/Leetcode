class LRUCache{
public:
    LRUCache(int capacity) 
    {
        size = capacity;
    }
    
    int get(int key) 
    {
        if(mp.find(key) != mp.end())
        {
            node* p = mp[key];
            node* q = mp[key]->next;
            p->next = q->next;
            if(q->next) 
                mp[q->next->k] = p;
            else
                tail = p;
            q->next = head->next;
            if(head->next) 
                mp[head->next->k] = q;
            else
                tail = q;
            head->next = q;
            mp[q->k] = head;
            return mp[key]->next->val;
        }
        return -1;
    }
    
    void set(int key, int value) 
    {
        if(mp.find(key) != mp.end())
        {
            node* p = mp[key];
            node* q = mp[key]->next;
            p->next = q->next;
            if(q->next) 
                mp[q->next->k] = p;
            else
                tail = p;
            q->next = head->next;
            if(head->next) 
                mp[head->next->k] = q;
            else
                tail = q;
            head->next = q;
            mp[q->k] = head;
            q->val = value;
            return ;
        }
        if(now < size)
        {
            now++;
            node* p = new node(key, value);
            mp[key] = head;
            if(head->next) mp[head->next->k] = p;
            
            p->next = head->next; 
            head->next = p;
            if(!p->next) tail = p;
            return ;
        }
        if(tail)
        {
            node* p = new node(key, value);
            mp[key] = head;
            if(head->next) mp[head->next->k] = p;
            p->next = head->next; 
            head->next = p;
            tail = mp[tail->k];
            mp.erase(tail->next->k);
            delete tail->next;
            tail->next = NULL;
        }
    }
    
private:
    struct node
    {
        int k,val;
        node* next;
        node(int a, int b)
        {
            k = a;
            val = b;
            next = NULL;
        }
    };
    node* head = new node(-1, -1);
    node* tail;
    int size, now = 0;
    unordered_map<int, node*> mp;
};