class Solution {
public:
    string minWindow(string s, string t) 
    {
        int maxlen=INT_MAX;
        string result;
        unordered_map<char,int> mp,mp2;
        int cnt=t.size();
        for(int i=0;i<cnt;i++) mp[t[i]]++;
        for(int st=0,en=0;en<s.size();en++)
        {
            if(mp[s[en]]>0 )
            {
                mp2[s[en]]++;
                if(mp2[s[en]]<=mp[s[en]]) cnt--;
            }
            if(cnt==0)
            {
                while((mp2[s[st]]==0 || mp2[s[st]]>mp[s[st]]) && st<=en) 
                {
                    if(mp2[s[st]]>mp[s[st]]) mp2[s[st]]--;
                    st++;
                }
                if(en-st+1<maxlen) 
                {
                    maxlen=en-st+1;
                    result=s.substr(st,en-st+1);
                }
                cnt++;
                mp2[s[st]]--;
                st++;
            }
        }
        return result;
    }
};