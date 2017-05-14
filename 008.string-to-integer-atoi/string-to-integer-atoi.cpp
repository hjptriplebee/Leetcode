class Solution {
public:
    int myAtoi(string str) {
        if(str.length()==0)
            return 0;
        int flag=0,first=0;
        while(str[first]==' ')
            first++;
        if(str[first]=='-')
        {
            flag=1;
            first++;
        }
        else if(str[first]=='+')
            first++;
        if(str[first]<'0' || str[first]>'9')
            return 0;
        long long ans=0;
        int cnt=0;
        for(int i=first;i<str.length();i++)
        {
            cnt++;
            if(cnt>17)
            {
                if(flag)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
            if(str[i]<'0' || str[i]>'9')
                break;
            ans*=(long long)10;
            ans+=(long long)(str[i]-'0');
        }
        if(flag)
            ans=-ans;
        if(ans>INT_MAX)
            return INT_MAX;
        if(ans<INT_MIN)
            return INT_MIN;
        return (int)ans;
    }
};