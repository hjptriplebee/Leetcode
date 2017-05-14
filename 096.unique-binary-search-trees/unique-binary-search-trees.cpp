class Solution {
public:
    int dp[50];
    int numTrees(int n) {
        if(n<=1) return 1;
        int res=0;
        for(int mid=1;mid<=n/2;mid++)
        {
            if(dp[mid-1]==0) dp[mid-1]=numTrees(mid-1);
            if(dp[n-mid]==0) dp[n-mid]=numTrees(n-mid);
            res+=dp[mid-1]*dp[n-mid];
        }
        res*=2;
        if(n%2) 
        {
            if(dp[n/2]==0) dp[n/2]=numTrees(n/2);
            res+=dp[n/2]*dp[n/2];
        }
        return res;
    }
};