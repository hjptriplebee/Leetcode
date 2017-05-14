class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> dp(ratings.size(), 1);
        int res = 0;
        for(int i = 1; i < ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1]) dp[i] = dp[i-1] + 1;
        }
        for(int i = ratings.size()-2;i >= 0 ;i--)
        {
            if(ratings[i] > ratings[i+1]) dp[i] = max(dp[i], dp[i+1] + 1) ;
            res += dp[i];
        }
        return res + dp[ratings.size()-1];
    }
};