class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0) return 0;
        vector<int> row(obstacleGrid[0].size()+1,0);  
        vector<vector<int>> dp(obstacleGrid.size()+1,row);  
        dp[0][1]=1;  
        for(int i=1;i<=obstacleGrid.size();i++)  
            for(int j=1;j<=obstacleGrid[0].size();j++)
                if(obstacleGrid[i-1][j-1]==0)
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
        return dp[obstacleGrid.size()][obstacleGrid[0].size()];  
    }
};