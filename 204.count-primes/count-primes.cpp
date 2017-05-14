class Solution {
public:
    int countPrimes(int n) {
        vector<bool> mp(n, 0);
        int res = 0;
        for(int i = 2 ; i < n ; i++)
        {
            if(!mp[i])
            {
                res++;
                if(i <= sqrt(n)) for(int j = i * i ; j < n ;j += i) mp[j] = 1;
            }
        }
        return res;
    }
};