class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int l=0,r=matrix.size()*matrix[0].size()-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            int com=matrix[mid/matrix[0].size()][mid%matrix[0].size()];
            if(com==target) return true;
            if(com<target)
                l=mid+1;
            else
                r=mid-1;
        }
        return false;
    }
};