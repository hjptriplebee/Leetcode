class node
{
    public:
    int flag;
    node* next[26];
    node(int x = 0)
    {
        flag = x;
        memset(next, 0, sizeof(next));
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    node* root;
    Trie() {
        root = new node();
    }
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        node* p = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!p->next[word[i] - 'a']) p->next[word[i] - 'a'] = new node();
            p = p->next[word[i] - 'a'];
        }
        p->flag = 1;
    }
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        node* p = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!p->next[word[i] - 'a']) return false;
            p = p->next[word[i] - 'a'];
        }
        return p->flag == 1;
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        node* p = root;
        for(int i = 0; i < prefix.size(); i++)
        {
            if(!p->next[prefix[i] - 'a']) return false;
            p = p->next[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */