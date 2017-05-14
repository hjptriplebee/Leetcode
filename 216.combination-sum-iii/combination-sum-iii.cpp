class Solution {
public:
    void dfs(int k, int now, int n, int sum, vector<vector<int>> &res, vector<int> path)
    {
        if(sum > n) return ;
        if(k == 0)
        {
            if(sum == n) res.push_back(path);
            return ;
        }
        if(now == 0) return ;
        for(int i = now; i > 0; i--)
        {
            vector<int> tmp = path;
            tmp.push_back(i);
            dfs(k-1, i - 1, n, sum + i, res, tmp);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(k, 9, n, 0, res, path);
        return res;
    }
};