class Solution {
public:
    int calculate(string s) {
        stack<int> op, ss;
        int now = 0, sum = 0, flag = 1;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9') now = now * 10 + s[i] - '0';
            else
            {
                sum += flag * now;
                now = 0;
                if(s[i] == ' ')continue;
                else if(s[i] == '+') flag = 1;
                else if(s[i] == '-') flag = -1;
                else if(s[i] == '(')
                {
                    ss.push(sum);
                    op.push(flag);
                    sum = 0;
                    flag = 1;
                }
                else 
                {
                    sum = ss.top() + sum * op.top();
                    op.pop();
                    ss.pop();
                }
            }
        }
        return sum + now * flag;
    }
};