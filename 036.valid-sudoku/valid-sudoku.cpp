class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int cnt=0;
        for(int i=0;i<7;i+=3)
        {
            for(int j=0;j<7;j+=3)
            {   //9宫格
                int vis=0,vis1=0,vis2=0;
                for(int k=0;k<3;k++)
                    for(int l=0;l<3;l++)
                    {
                        if(board[i+k][j+l]=='.') continue;
                        if((1<<(board[i+k][j+l]-'0') & vis)==0)
                            vis|=(1<<(board[i+k][j+l]-'0'));
                        else
                            return false;
                    }
                for(int k=0;k<9;k++)
                {
                    if(board[cnt][k]!='.')
                    {
                        if((1<<(board[cnt][k]-'0') & vis2)==0)
                            vis2|=(1<<(board[cnt][k]-'0'));
                        else
                            return false;
                    }
                    if(board[k][cnt]!='.')
                    {
                        if((1<<(board[k][cnt]-'0') & vis1)==0)
                            vis1|=(1<<(board[k][cnt]-'0'));
                        else
                            return false;
                    }
                }
                cnt++;
            }
        }
        return true;
    }
};