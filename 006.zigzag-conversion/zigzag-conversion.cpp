class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int len=s.length(),now=0;
        string result;
        while(now<len)
        {
            result+=s[now];
            now+=(2*numRows-2);
        }
        for(int i=1;i<numRows-1;i++)
        {
            now=0;
            int cnt=0;
            while(now<len)
            {
                cnt++;
                if(cnt%2)
                {
                    now=(cnt-1)*(numRows-1)+i;
                }
                else
                {
                    now=(cnt-1)*(numRows-1)+numRows-i-1;
                }
                if(now>=len) continue;
               // cout<<now<<endl;
                result+=s[now];
            }
            
        }
        now=numRows-1;
        while(now<len)
        {
            result+=s[now];
            now+=(2*numRows-2);
        }
        return result;
    }
};