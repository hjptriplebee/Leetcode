class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m=matrix.size();
        if(m==0) return result;
        int n=matrix[0].size(),x=0,y=0;
        for(;x<m && y<n;x++,y++,m--,n--)
        {
            for(int i=y;i<n;i++) result.push_back(matrix[x][i]);
            for(int i=x+1;i<m;i++) result.push_back(matrix[i][n-1]);
            for(int i=n-2;i>=y && x!=m-1;i--) result.push_back(matrix[m-1][i]);
            for(int i=m-2;i>x && y!=n-1;i--) result.push_back(matrix[i][y]);
        }
        return result;
    }
};