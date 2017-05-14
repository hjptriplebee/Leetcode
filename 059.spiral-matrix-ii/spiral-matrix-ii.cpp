class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row(n,0);
        vector<vector<int>> result(n,row);
        int rows=n,cols=n,cnt=0;
        for(int x=0,y=0;x<rows && y<cols;x++,y++)
        {
            for(int i=y;i<cols;i++) result[x][i]=++cnt;
            for(int i=x+1;i<rows;i++) result[i][cols-1]=++cnt;
            for(int i=cols-2;i>=y ;i--) result[rows-1][i]=++cnt;
            for(int i=rows-2;i>x ;i--) result[i][y]=++cnt;
            rows--;
            cols--;
        }
        return result;
    }
};