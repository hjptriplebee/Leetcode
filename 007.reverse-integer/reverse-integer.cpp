class Solution 
{
public:
    int reverse(int x) 
    {
        long long ans=0,flag=0,x1=x;
        if(x1<0)
        {//cout<<x<<endl;
            x1=-x1;
           // cout<<x<<endl;
            flag=1;
        }
       // cout<<x<<endl;
        while(x1)
        {
            ans*=(long long)10;
            ans+=((long long)x1%10);
            x1/=10;
           // cout<<ans<<endl;
        }
        
        if(ans>INT_MAX)
            return 0;
        if(flag)
            ans=-ans;
        return (int)ans;
    }
};