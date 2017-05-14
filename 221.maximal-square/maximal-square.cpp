class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0;
        for(int i = 0; i < matrix.size(); i ++)
        {
            for(int j = 0; j < matrix[0].size(); j ++)
            {
                if(matrix[i][j] == '0') 
                {
                    matrix[i][j] = 0;
                    continue;
                }
                int l = 0, u = 0, lu = 0;
                if(i != 0 && j != 0) lu = matrix[i - 1][j - 1];
                if(i != 0) l = matrix[i - 1][j];
                if(j != 0) u = matrix[i][j - 1];
                matrix[i][j] = 1 + min(min(l, u), lu);
                res = max(res, matrix[i][j] * matrix[i][j]);
            }
        }
        return res;
    }
};