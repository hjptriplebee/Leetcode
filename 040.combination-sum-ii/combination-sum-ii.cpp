class Solution {
public:
    void dfs(vector<int> candidates,int target,vector<vector<int>>& result,vector<int> path)  
    {  
        if(target==0)  
        {  
            result.push_back(path);      
            return ;  
        } 
        int t;
        for(int i=candidates.size()-1;i>=0;i--)  
        {  
            if(candidates[i]==t) 
            {
                candidates.pop_back();
                continue;
            }
            t=candidates[i];
            candidates.pop_back();
            if(t>target) continue;  
            path.push_back(t);  
            dfs(candidates,target-t,result,path);  
            path.pop_back();  
        }  
    }  
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)   
    {  
        vector<vector<int>> result;  
        vector<int> path;  
        sort(candidates.begin(),candidates.end());  
        dfs(candidates,target,result,path);  
        return result;  
    } 
};