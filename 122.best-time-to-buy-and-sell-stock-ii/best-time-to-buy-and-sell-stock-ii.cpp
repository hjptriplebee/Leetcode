class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int res=0,pre=prices[0];
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i+1]>prices[i]) res+=prices[i+1]-prices[i];
            pre=prices[i+1];
        }
        return res;
    }
};