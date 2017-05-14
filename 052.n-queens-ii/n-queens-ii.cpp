class Solution {
public:
     bool judge(vector<int> col,int nowRow)  
    {  
        for(int i=0;i<nowRow;i++)  
            if(col[i] == col[nowRow] || abs(col[nowRow]-col[i])==abs(i-nowRow)) return false;  
        return true;  
    }  
    void dfs(int nowRow,int &result,vector<int> col)  
    {  
        int n=col.size();  
        if(nowRow==n)  
        {  
            result++;
            return ;  
        }  
        for(col[nowRow]=0;col[nowRow]<n;col[nowRow]++)  
            if(judge(col,nowRow))  
                dfs(nowRow+1,result,col);  
    }  
    int totalNQueens(int n) 
    {
        int result=0;
        vector<int> col(n);
        dfs(0,result,col);
        return result;
    }
};