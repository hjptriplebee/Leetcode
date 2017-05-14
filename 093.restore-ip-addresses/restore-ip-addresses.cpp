class Solution {
public:
    bool judge(string s)
    {
        if((s.size()>1 && s[0]=='0') || s.empty()) return false; 
        int res=0;
        for(int i=0;i<s.size();i++) res=res*10+s[i]-'0';
        return (res>=0 && res<=255) ? true:false;
    }
    void dfs(vector<string>& res,string s,int now,string ip)
    {
        if(now==3)
        {
            if(judge(s)) res.push_back(ip+s);
            return ;
        }
        int limit=min((int)s.size(),3);
        for(int i=1;i<=limit;i++)
        {
            string temp=s.substr(0,i);
            if(judge(temp)) dfs(res,s.substr(i),now+1,ip+temp+'.');
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(res,s,0,"");
        return res;
    }
};