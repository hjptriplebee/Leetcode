class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i<= s.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(!dp[j]) continue;
                if(wordDict.find(s.substr(j, i-j)) != wordDict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};