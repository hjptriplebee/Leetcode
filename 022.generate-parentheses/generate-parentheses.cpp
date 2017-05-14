class Solution {
public:
    void dfs(vector<string> &v,string s,int l,int r)
    {
        if(l==0 && r==0)
            v.push_back(s);
        if(l!=0)
            dfs(v,s+"(",l-1,r);
        if(r>l)
            dfs(v,s+")",l,r-1);
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> result;
        dfs(result,"",n,n);
        return result;
    }
};