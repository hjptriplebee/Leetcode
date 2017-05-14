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
class WordDictionary {
public:
    node* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new node();
    }
    /** Adds a word into the data structure. */
    void addWord(string word) {
        node* p = root;  
        for(int i = 0; i < word.size(); i++)  
        {  
            if(!p->next[word[i] - 'a']) p->next[word[i] - 'a'] = new node();  
            p = p->next[word[i] - 'a'];  
        }  
        p->flag = 1; 
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word, root);
    }
    bool dfs(string word, node* now)
    {
        if(word.size() == 0) 
        {
            if(now->flag) return true;
            return false;
        }
        if(word[0]!='.')
        {
            if(!now->next[word[0] - 'a']) return false;
            return dfs(word.substr(1), now->next[word[0]-'a']);
        }
        else
            for(int i = 0; i < 26; i++) if(now->next[i] && dfs(word.substr(1), now->next[i])) return true;
        return false;
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */