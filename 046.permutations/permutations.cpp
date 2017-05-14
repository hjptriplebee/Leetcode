class Solution {
public:
    void dfs(vector<vector<int>> &result,vector<int> nums,vector<int> now)
    {
        if(nums.size() == 0)
        {
            result.push_back(now);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            now.push_back(nums[i]);
            vector<int> temp=nums;
            temp.erase(temp.begin()+i);
            dfs(result,temp,now);
            now.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result;
        vector<int> now;
        dfs(result,nums,now);
        return result;
    }
};