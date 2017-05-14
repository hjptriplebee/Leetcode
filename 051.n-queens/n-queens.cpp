class Solution {
public:
    bool judge(vector<int> col,int nowRow)
    {
        for(int i=0;i<nowRow;i++)
            if(col[i] == col[nowRow] || abs(col[nowRow]-col[i])==abs(i-nowRow)) return false;
        return true;
    }
    void dfs(vector<vector<string>> &result,int nowRow,vector<string> temp,vector<int> col)
    {
        int n=col.size();
        if(nowRow==n)
        {
            result.push_back(temp);
            return ;
        }
        temp.push_back(string(n,'.'));
        for(col[nowRow]=0;col[nowRow]<n;col[nowRow]++)
            if(judge(col,nowRow))
            {
                vector<string> temp2=temp;
                temp2[nowRow][col[nowRow]]='Q';
                dfs(result,nowRow+1,temp2,col);
            }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> result;
        vector<string> temp;
        vector<int> col(n);
        dfs(result,0,temp,col);
        return result;
    }
};