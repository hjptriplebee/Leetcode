class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int i = 0, j = matrix.size() - 1;
        while(i < matrix[0].size() && j >= 0)
        {
            if(matrix[j][i] == target) return true;
            else if (matrix[j][i] > target) j--;
            else i++;
        }
        return false;
    }
};