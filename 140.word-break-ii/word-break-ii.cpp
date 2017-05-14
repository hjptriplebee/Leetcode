class Solution {
public:
    void dfs(vector<string> &res, string now, vector<vector<int>>& dp, int index, string& s)
    {
        if (index == 0)
        {
            now = now.substr(0, now.size()-1);
            res.push_back(now);
            return ;
        }
        for(int i = 0; i < dp[index].size(); i++)
        {
            dfs(res, s.substr(dp[index][i], index - dp[index][i])+" "+ now, dp, dp[index][i], s);
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<int> temp;
        vector<vector<int>> dp(s.size()+1, temp);  
        dp[0].push_back(0);  
        for (int i = 1; i<= s.size(); i++)  
        {  
            for(int j = 0; j < i; j++)  
            {  
                if(dp[j].empty()) continue;  
                if(wordDict.find(s.substr(j, i-j)) != wordDict.end()) dp[i].push_back(j);
            }  
        }
        vector<string> res;
        string now;
        dfs(res, now, dp, s.size(), s);
        return res;  
    }
};