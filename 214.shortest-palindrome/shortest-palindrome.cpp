class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        t = s + '#' + t;
        vector<int> next(2 * s.size() + 1, 0);
        for(int i = 1; i < t.size(); i++)
        {
            int pre = next[i - 1];
            while(t[pre] != t[i] && pre != 0) pre = next[pre - 1];
            if(t[pre] == t[i]) pre++;
            next[i] = pre;
        }
        return t.substr(s.size() + 1, s.size() - next[t.size() - 1]) + t.substr(0, s.size());
    }
};