class Solution {
public:
    vector<int> set;
    int find(int x)
    {
        if(x!=set[x]) set[x] = find(set[x]);
        return set[x];
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        for(int i = 0;i < m * n; i++) set.push_back(i);
        for(int i = 0; i < m ; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int x = i * n + j;
                if(grid[i][j] == '0')
                {
                    set[x] = -1;
                    continue;
                }
                if(i != 0 && grid[i-1][j] == '1')
                {
                    int y = (i - 1) * n + j;
                    set[find(x)] = find(y);
                }
                if(j != 0 && grid[i][j-1] == '1')
                {
                    int y = i * n + j -1;
                    set[find(x)] = find(y);
                }
            }
        }
        int res = 0;
        unordered_map<int, int> mp;
        for(int i = 0 ;i < m * n ; i++)
        {
            if(set[i] == -1) continue;
            int y = find(i);
            if(!mp[y])
            {
                res++;
                mp[y] = 1;
            }
        }
        
        return res;
    }
};