class Solution {
public:
    int mySqrt(int x) {
        long long l=0,r=x,mid;
        while(l<=r)
        {
            mid=(l+r)>>1;
            long long ans=mid*mid;
            if(ans<=x && (mid+1)*(mid+1)>x) 
                return mid;
            if(ans>x) 
                r=mid-1;
            else
                l=mid+1;
        }
        return mid;
    }
};