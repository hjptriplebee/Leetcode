class Solution {
public:
    bool judge(string s)
    {
        for(int i=0;i<s.size()/2;i++) if(s[i] != s[s.size()-1-i]) return false;
        return true;
    }
    void dfs(string s,vector<vector<string>>& res, vector<string>& now)
    {
        if(s.empty())
        {
            res.push_back(now);
            return ;
        }
        for(int i=1;i<=s.size();i++)
        {
            if(judge(s.substr(0,i)))
            {
                vector<string> temp=now;
                temp.push_back(s.substr(0,i));
                dfs(s.substr(i), res, temp);
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> res;
        vector<string> temp;
        dfs(s,res,temp);
        return res;
    }
};