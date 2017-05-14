class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_map<string,vector<string>> mp;
        wordList.insert(beginWord);
        wordList.insert(endWord);
        for(unordered_set<string>::iterator it=wordList.begin();it!=wordList.end();it++)
        {
            string cc=*it;
            for(int i=0;i<cc.size();i++)
            {
                string c=*it;
                for(char j='a';j<='z';j++)
                {
                    c[i]=j;
                    if(wordList.find(c)!=wordList.end())
                    {
                        mp[*it].push_back(c);
                    }
                }
            }
        }
        queue<string> q,q2;
        unordered_map<string,bool> vis;
        q.push(beginWord);
        vis[beginWord]=true;
        int res=0,flag=1;
        while(!q.empty() || !q2.empty())
        {
            if(!q.empty())
            {
                string temp=q.front();
                q.pop();
                if(temp==endWord)
                {
                    res=flag;
                    break;
                }
                for(int i=0;i<mp[temp].size();i++)
                {
                    string tt=mp[temp][i];
                    if(vis[tt]) continue;
                    vis[tt]=true;
                    q2.push(tt);
                }
            }
            else
            {
                flag++;
                swap(q,q2);
            }
        }
        
        return res;
    }
};