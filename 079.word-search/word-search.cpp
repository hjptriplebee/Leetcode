class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int x,int y,vector<vector<bool>>& vis)
    {
        if(word.empty()) return true;
        if(x+1<board.size() && word[0]==board[x+1][y] && !vis[x+1][y])
        {
            vis[x+1][y]=true;
            if(dfs(board,word.substr(1,word.size()-1),x+1,y,vis)) return true;
            vis[x+1][y]=false;
        }
        if(x-1>=0 && word[0]==board[x-1][y] && !vis[x-1][y]) 
        {
            vis[x-1][y]=true;
            if(dfs(board,word.substr(1,word.size()-1),x-1,y,vis)) return true;
            vis[x-1][y]=false;
        }
        if(y+1<board[0].size() && word[0]==board[x][y+1] && !vis[x][y+1]) 
        {
            vis[x][y+1]=true;
            if(dfs(board,word.substr(1,word.size()-1),x,y+1,vis)) return true;
            vis[x][y+1]=false;
        }
        if(y-1>=0 && word[0]==board[x][y-1] && !vis[x][y-1]) 
        {
            vis[x][y-1]=true;
            if(dfs(board,word.substr(1,word.size()-1),x,y-1,vis)) return true;
            vis[x][y-1]=false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return true;
        vector<bool> temp(board[0].size(),false);
        vector<vector<bool>> vis(board.size(),temp);
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(word[0]==board[i][j])
                {
                    vis[i][j]=true;
                    if(dfs(board,word.substr(1,word.size()-1),i,j,vis)) return true;
                    vis[i][j]=false;
                }
        
        return false;
    }
};