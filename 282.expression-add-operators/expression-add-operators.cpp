class Solution {
public:
    void dfs(vector<string> &res, string &num, int target, string now, int pos, long long sum, long long sum2, char op)
    {
        if(num.size() == pos)
        {
            if(target == sum2) res.push_back(now);
            return ;
        }
        for(int i = pos + 1; i <= num.size(); i++)
        {
            string tmp = num.substr(pos, i - pos);
            long long tmp2 = stoll(tmp);
            if(to_string(tmp2) != tmp) break;
            if(op == '#')
            {
                dfs(res, num, target, now + tmp, i, sum, tmp2, '*');
                continue;
            }
            if(op == '+')dfs(res, num, target, now + "*" + tmp, i, sum, (sum2 - sum) * tmp2 + sum, '*');
            else if(op == '-') dfs(res, num, target, now + "*" + tmp, i, sum, sum - (sum - sum2) * tmp2, '*');
            else if(op == '*') dfs(res, num, target, now + "*" + tmp, i, sum, sum + (sum2 - sum) * tmp2, '*');
            dfs(res, num, target, now + "+" + tmp, i, sum2, sum2 + tmp2, '+');
            dfs(res, num, target, now + "-" + tmp, i, sum2, sum2 - tmp2, '-');
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(res, num, target, "", 0, 0, 0, '#');
        return res;
    }
};