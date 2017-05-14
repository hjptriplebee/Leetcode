class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1=INT_MIN,b2=INT_MIN;
        int s1=0,s2=0;
        for(int i=0;i<prices.size();i++)
        {
            b1=max(b1,-prices[i]);
            s1=max(s1,b1+prices[i]);
            b2=max(b2,s1-prices[i]);
            s2=max(s2,b2+prices[i]);
        }
        return s2;
    }
};