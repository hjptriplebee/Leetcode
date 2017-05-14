class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int res=0;
       for(int i=1;i<prices.size();i++)
       {
           res=max(res,prices[i]-prices[i-1]);
           prices[i]=min(prices[i],prices[i-1]);
       }
       return res;
    }
};