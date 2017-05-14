class Solution {
public:
    int toint(string s)
    {
        int res = 0,i = 0;
        if(s[0] == '-') i = 1;
        for(; i < s.size(); i++)
        {
            res *=10;
            res += s[i]-'0';
        }
        //cout<<res<<endl;
        return s[0] == '-' ? -res : res;
    }
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++)
        {
            int a, b;
            if(tokens[i] == "+")
                a = s.top(), s.pop(), b = s.top(), s.pop(), s.push(a+b);
            else if(tokens[i] == "-")
                a = s.top(), s.pop(), b = s.top(), s.pop(), s.push(b-a);
            else if(tokens[i] == "*")
                a = s.top(), s.pop(), b = s.top(), s.pop(), s.push(a*b);
            else if(tokens[i] == "/")
                a = s.top(),s.pop(), b = s.top(), s.pop(), s.push(b/a);
            else
                s.push(toint(tokens[i]));
        }
        return s.top();
    }
};