class Solution {
public:
    bool isMatch(string s, string p) {
        //cout<<s<<endl<<p<<endl<<"y"<<endl;
        int len1=s.length(),len2=p.length();
        if(len2==0)
            return len1==0;
        if(len2==1)
            return (len1==1) && (s[0]==p[0] || p[0]=='.');
        if(p[1]=='*')
        {
            for(int i=0;i<len1 && (p[0]==s[i] || p[0]=='.');i++)
                if(isMatch(s.substr(i+1,len1-i-1),p.substr(2,len2-2)))
                    return true;
            return isMatch(s,p.substr(2,len2-2));
        }
        else
        {
            if(len1==0)
                return false;
            else
                return isMatch(s.substr(1,len1-1),p.substr(1,len2-1)) && ((s[0]==p[0]) || (p[0]=='.'));
        }
            
    }
};