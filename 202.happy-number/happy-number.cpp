class Solution {
public:
    int fun(int x)
    {
        int ret = 0;
        while(x)
        {
            int now = x %10;
            x /= 10;
            ret += now * now;
        }
        return ret;
    }
    bool isHappy(int n) {
        while(1)
        {
            if(n == 1) return 1;
            if(n == 4) return 0;
            n = fun(n);
        }
    }
};