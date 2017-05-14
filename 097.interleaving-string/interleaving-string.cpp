class Solution {
public:
    bool dfs(string s1,string s2,string s3,map<pair<int,int>,int>& mp)
    {
        if(s3.empty()) return true;
        pair<int,int> temp=make_pair(s1.size(),s2.size());
        if(mp[temp]) return false;
        mp[temp]=1;
        if(!s1.empty() && s1[0]==s3[0] && dfs(s1.substr(1),s2,s3.substr(1),mp)) return true;
        if(!s2.empty() && s2[0]==s3[0] && dfs(s1,s2.substr(1),s3.substr(1),mp)) return true;
        
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        map<pair<int,int>,int> mp;
        return dfs(s1,s2,s3,mp);
    }
};