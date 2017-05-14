class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows < 1) return res;
        vector<int> temp(1,1);
        res.push_back(temp);
        for(int i=1;i<numRows;i++)
        {
            
            temp.clear();
            temp.push_back(1);
            for(int j=0;j<res[i-1].size()-1;j++) temp.push_back(res[i-1][j]+res[i-1][j+1]);
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};