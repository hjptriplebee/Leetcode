class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(1,1);
        for(int i=1;i<=rowIndex;i++)
        {
            vector<int> temp=res;
            for(int j=0;j<res.size()-1;j++) temp[j+1]=res[j]+res[j+1];
            res=temp;
            res.push_back(1);
        }
        return res;
    }
};