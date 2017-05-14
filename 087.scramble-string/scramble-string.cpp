class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2) return true;
        int cnt[256]={0};
        for(int i=0;i<s1.size();i++) 
        {
            cnt[s1[i]]++;
            cnt[s2[i]]--;
        }
        for(char i='a';i<='z';i++)
            if(cnt[i]!=0)
                return false;
        for(int i=1;i<s1.size();i++)
            if((isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i))) || (isScramble(s1.substr(0,i),s2.substr(s1.size()-i)) && isScramble(s1.substr(i),s2.substr(0,s1.size()-i)))) 
            return true;
        return false;
    }
};