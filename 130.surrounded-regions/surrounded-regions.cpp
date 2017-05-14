class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() < 3 || board[0].size() < 3) {
        	return;
        }
        int i = 0, j = 0, row = board.size(), column = board[0].size();
        vector<vector<int>> offset = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		while(true) {
			if(board[i][j] == 'O') {
				board[i][j] = 'A';
				queue<pair<int, int>> que;
				que.push(make_pair(i, j));
				while(!que.empty()) {
					auto p = que.front();
					que.pop();
					for(const auto& ints : offset) {
						int ti = p.first+ints[0], tj = p.second+ints[1];
						if(ti < row && ti >= 0 && tj < column && tj >= 0 && board[ti][tj] == 'O') {
							board[ti][tj] = 'A';
							que.push(make_pair(ti, tj));
						}
					}
				}
			}
			if(i == 0) {
				if(j < column-1) j++;
				else i++;
			} else if (j == column-1) {
			    if(i < row-1) i++;
			    else j--;
			} else if (i == row-1) {
				if(j > 0) j--;
			    else i--;
			} else {
				if(i > 1)  i--;
				else break;
			}
		}
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < column; j++) {
				if(board[i][j] == 'A') {
					board[i][j] = 'O';
				} else if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
    }
};