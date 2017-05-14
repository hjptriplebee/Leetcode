class Solution {
public:
    bool dfs(int dep,vector<vector<char>>& board,int vis[],int vis2[],int vis3[])
    {
        if(dep==81) return true;
        int x=dep/9,y=dep%9;
        if(board[x][y]!='.')
            return dfs(dep+1,board,vis,vis2,vis3);
        else
        {
            for(int i=1;i<10;i++)
            {
                if(vis[x]&(1<<i) || vis2[y]&(1<<i) || vis3[x/3*3+y/3]&(1<<i)) continue;
                vis[x]|=(1<<i);
                vis2[y]|=(1<<i);
                vis3[x/3*3+y/3]|=(1<<i);
                if(dfs(dep+1,board,vis,vis2,vis3))
                {
                    board[x][y]='0'+i;
                    return true;
                }
                vis[x]&=~(1<<i);
                vis2[y]&=~(1<<i);
                vis3[x/3*3+y/3]&=~(1<<i);
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        int vis[9]={0},vis2[9]={0},vis3[9]={0};
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j]!='.')
                {
                    int t=board[i][j]-'0';
                    vis[i]|=(1<<t);
                    vis2[j]|=(1<<t);
                    vis3[i/3*3+j/3]=(1<<t);
                }
        dfs(0,board,vis,vis2,vis3);
    }
};