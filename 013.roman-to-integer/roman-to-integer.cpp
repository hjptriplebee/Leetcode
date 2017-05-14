class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int result=0,pre=0;
        for(int i=0;i<s.length();i++)
        {
            if(mp[s[i]]>pre)
                result+=mp[s[i]]-2*pre;
            else
                result+=mp[s[i]];
            pre=mp[s[i]];
        }
        return result;
    }
};