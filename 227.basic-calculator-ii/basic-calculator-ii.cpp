class Solution {
public:
    int calculate(string s) {
        stack<int> ss;
        int now = 0, flag = 1, temp;
        s += "#";
        bool flagd = false, flagm = false;
        for(int i = 0; i < s.size(); i ++)
        {
            if(s[i] == ' ') continue;
            if(s[i] >= '0' && s[i] <= '9') now = now * 10 + s[i] - '0'; 
            else if(flagm)
            {
                i--;
                flagm = false;
                now *= temp;
            }
            else if(flagd)
            {
                i--;
                flagd = false;
                now = temp / now;
            }
            else if(s[i] == '#') continue;
            else if(s[i] == '+')
            {
                ss.push(flag * now);
                flag = 1;
                now = 0;
            }
            else if(s[i] == '-')
            {
                ss.push(flag * now);
                flag = -1;
                now = 0;
            }
            else
            {
                temp = now;
                now = 0;
                if(s[i] == '*') flagm = true;
                else flagd = true;
            }
        }
        now *= flag;
        while(!ss.empty())
        {
            now += ss.top();
            ss.pop();
        }
        return now;
    }
};