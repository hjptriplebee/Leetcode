class Solution {
public:
    double myPow(double x, long long n) {
        double result=1,base=x;
        while(n)
        {
            if(n<0)
            {
                base=1/base;
                n=-n;
            }
            if(n&1) result*=base;
            base*=base;
            n>>=1;
        }
        return result;
    }
};