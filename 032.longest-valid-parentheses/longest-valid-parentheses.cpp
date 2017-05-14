class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int result=0;
        s=')'+s;
        vector<int> dp(s.length(),0);
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==')')
            {
                if(s[i-1-dp[i-1]]=='(') dp[i]=dp[i-1]+2;
                dp[i]+=dp[i-dp[i]];
            }
            //cout<<i<<" "<<dp[i]<<endl;
            result=max(result,dp[i]);
        }
        return result;
    }
};