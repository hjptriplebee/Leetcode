class Solution {
public:
    string simplifyPath(string path) {
        string result,temp;
        vector<string> s;
        path+='/';
        for(int i=0;i<path.size();i++)
        {
            if(path[i]=='/')
            {
                if(temp=="" || temp==".")
                {
                }
                else if(temp=="..")
                {
                    if(!s.empty()) s.pop_back();
                }
                else
                    s.push_back(temp);
                temp="";
            }
            else
                temp+=path[i];
        }
        if(!path.empty() && s.empty()) result+='/';
        for(int i=0;i<s.size();i++) result+='/'+s[i];
        return result;
    }
};