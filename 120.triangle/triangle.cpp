class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp=triangle;
        for(int i=1;i<dp.size();i++)
        {
            for(int j=0;j<dp[i].size();j++)
            {
                vector<int> temp;
                if(j!=0) temp.push_back(dp[i-1][j-1]);
                if(j!=dp[i].size()-1) temp.push_back(dp[i-1][j]);
                sort(temp.begin(),temp.end());
                dp[i][j]=temp[0]+dp[i][j];
            }
        }
        sort(dp[dp.size()-1].begin(),dp[dp.size()-1].end());
        return dp[dp.size()-1][0];
    }
};