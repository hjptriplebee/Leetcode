class Solution {
public:
    void dfs(vector<int>& candidates,int target,vector<vector<int>>& result,vector<int> path,int limit)
    {
        if(target==0)
        {
            result.push_back(path);    
            return ;
        }
        for(int i=candidates.size()-1;i>=0;i--)
        {
            if(candidates[i]>target || i>limit) continue;
            path.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],result,path,i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        for(int i=0;i<candidates.size();i++)
            if(i<(candidates.size()-1) && candidates[i]==candidates[i+1])
            {
                candidates.erase(candidates.begin()+i);
                i--;
            }
        dfs(candidates,target,result,path,candidates.size()-1);
        return result;
    }
};