class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n)
        {
            int c = (n % 26) - 1;
            if(c == -1) c = 25;
            res = char('A' + c) + res;
            n--;
            n /= 26;
        }
        return res;
    }
};