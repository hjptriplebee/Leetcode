class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) temp+=s[i];
            if((s[i]>='A' && s[i]<='Z') ) temp+=s[i]-'A'+'a';
        }
        string temp2=temp;
        reverse(temp.begin(),temp.end());
        return temp==temp2;
    }
};