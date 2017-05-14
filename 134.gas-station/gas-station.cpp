class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, minn = INT_MAX, pos;
        for(int i = 0;i < gas.size();i++)
        {
            sum+=(gas[i]-cost[i]);
            if(minn > sum)
            {
                minn = sum;
                pos = i;
            }
        }
        if(sum<0) return -1;
        return (pos+1) % gas.size();
    }
};