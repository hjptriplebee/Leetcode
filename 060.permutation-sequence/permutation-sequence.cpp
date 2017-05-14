class Solution {
public:
    string getPermutation(int n, int k) {
        int mp[10];
        mp[0]=mp[1]=1;
        vector<int> v(1,1);
        for(int i=2;i<10;i++)
        {
            mp[i]=mp[i-1]*i;
            v.push_back(i);
        }
        string result;
        while(n--)
        {
            vector<int>::iterator it=v.begin();
            while(k>mp[n])
            {
                k-=mp[n];
                it++;
            }
            result+=('0'+*it);
            v.erase(it);
            
        }
        return result;
    }
};