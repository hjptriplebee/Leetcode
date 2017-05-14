class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k > prices.size())
        {
            int res = 0;
            for(int i = 1 ; i < prices.size(); i++) if(prices[i] > prices[i-1]) res += prices[i]-prices[i-1];
            return res;
        }
        vector<int> sell(k+1, 0), buy(k+1, INT_MIN);
        for(int i = 0; i < prices.size() ; i++)
        {
            for(int  j = k; j > 0 ; j--)
            {
                sell[j] = max(sell[j], buy[j] + prices[i]);
                buy[j] = max(buy[j], sell[j-1] - prices[i]);
            }
        }
        return sell[k];
    }
};