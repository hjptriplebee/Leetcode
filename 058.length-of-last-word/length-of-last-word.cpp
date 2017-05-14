class Solution {
public:
    int lengthOfLastWord(string s) {
        int result=0,flag=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(!flag && s[i]==' ') continue;
            if(s[i]!=' ')
            {
                flag=1;
                result++;
            }
            else
                break;
        }
        return result;
    }
};