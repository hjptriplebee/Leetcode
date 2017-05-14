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
        //cout<<word<<endl;
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
class Solution {
public:
    WordDictionary tree;
    unordered_map<string, bool> mp;
    void dfs(vector<string> &res, vector<vector<char>>& board, int i,int j, string now)
    {
        if(board[i][j] == ' ') return ;
        now += board[i][j];
        if(!tree.startsWith(now)) return ;
        if(tree.search(now) && !mp[now]) 
        {
            mp[now] = true;
            res.push_back(now);
        }
        char temp = board[i][j];
        board[i][j] = ' ';
        if(i < board.size() - 1) dfs(res, board, i + 1, j, now);
        if(i > 0) dfs(res, board, i - 1, j, now);
        if(j < board[0].size() - 1) dfs(res, board, i, j + 1, now);
        if(j > 0) dfs(res, board, i, j - 1, now);
        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int m = board.size();
        if(m == 0) return res;
        int n = board[0].size();
        for(int i = 0; i < words.size(); i++) tree.addWord(words[i]);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                string temp;
                dfs(res, board, i, j, temp);
            }
        }
        return res;
    }
};