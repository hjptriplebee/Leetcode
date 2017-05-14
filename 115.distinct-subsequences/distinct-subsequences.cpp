class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> temp(s.size()+1,0);
        vector<vector<int>> dp(t.size()+1,temp);
        for(int i=0;i<=s.size();i++) dp[0][i]=1;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=1;j<=i && j<=t.size();j++)
            {
                dp[j][i]=dp[j][i-1];
                if(s[i-1]==t[j-1]) dp[j][i]+=dp[j-1][i-1];
            }
        }
        return dp[t.size()][s.size()];
    }
};