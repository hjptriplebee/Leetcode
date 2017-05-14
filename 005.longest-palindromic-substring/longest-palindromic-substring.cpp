class Solution 
{
public:
    string init(string s)
    {
        string result("*#");
        for(int i=0;i<s.length();i++)
        {
            result+=s[i];
            result+='#';
        }
        result+='&';
        return result;
    }
    string longestPalindrome(string s) 
    {
        string ch=init(s);
        int p[2010],id=0,maxlen=0,pos=0;
        p[0]=0;
        for(int i=1;i<ch.length();i++)
        {
            if(p[id]+id>i)
                p[i]=min(p[2*id-i],p[id]+id-i); 
            else
                p[i]=1;
            while(ch[i-p[i]] == ch[i+p[i]])
                p[i]++;  
            if(id+p[id]<i+p[i])
                id=i;  
            if(maxlen<p[i])
            {
                pos=i;
                maxlen=p[i];
            }
        }
        pos/=2;
        //cout<<pos<<" "<<maxlen<<endl;
        string result=s.substr(pos-maxlen/2,maxlen-1);
        return result;
    }
};