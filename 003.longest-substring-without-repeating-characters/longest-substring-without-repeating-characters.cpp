class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int len=s.length();
        int st=0,en=0,result=0;
        int vis[1005];
        memset(vis,0,sizeof(vis));
        while(en<len)
        {
            int now=s[en];
            while(st<en && vis[now])
            {
                vis[s[st]]=0;
                st++;
            }
            vis[now]=1;
            en++;
            result=max(result,en-st);
        }
        return result;
    }
};