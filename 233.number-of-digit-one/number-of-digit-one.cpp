class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for(long long i = 1; i <= n ; i *= 10)
        {
            int pre = n / i;
            int suf = n % i;
            long long temp = (pre + 8) / 10 * i;
            if(pre % 10 == 1) temp += suf + 1;
            res += temp;
        }
        return res;
    }
};