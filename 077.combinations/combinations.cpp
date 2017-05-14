class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp(k,0);
        int now=0;
        while(now>=0)
        {
            temp[now]++;
            if(temp[now]>n) 
                now--;
            else if(now==k-1) 
                result.push_back(temp);
            else
            {
                temp[now+1]=temp[now];
                now++;
            }
        }
        return result;
    }
};