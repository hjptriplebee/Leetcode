class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string dic[11]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;
        queue <string> q;
        q.push("");
        for(int i=0;i<digits.length();i++)
        {
            int cnt=q.size();
            while(cnt--)
            {
                string temp=q.front();
                //cout<<temp<<endl;
                q.pop();
                for(int j=0;j<dic[digits[i]-'0'].length();j++)
                    q.push(temp+dic[digits[i]-'0'][j]);
            }
        }
        if(q.front()=="") q.pop();
        while(!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};