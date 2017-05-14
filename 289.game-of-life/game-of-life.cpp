class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        int n = board.size();
        if(!n) return;
        int m = board[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int cnt = 0;
                for(int k = 0; k < 8 ; k++)
                {
                    int x = i + dir[k][0], y = j + dir[k][1];
                    if(x < 0 || x >= n || y < 0 || y >= m) continue;
                    if(board[x][y] & 1) cnt++;
                }
                if(cnt == 2) board[i][j] |= (board[i][j] & 1) << 1;
                else if(cnt == 3) board[i][j] |= 1 << 1;
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                board[i][j] >>= 1;
    }
};