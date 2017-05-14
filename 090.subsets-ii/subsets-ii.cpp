class Solution {
public:
    void dfs(vector<vector<int>>& res,vector<int> nums,vector<int> now)
    {
        if(nums.size()==0)
        {
            res.push_back(now);
            return ;
        }
        vector<int> temp=now;
        int back=nums[nums.size()-1];
        nums.pop_back();
        now.push_back(back);
        dfs(res,nums,now);
        while(nums.size()>0 && nums[nums.size()-1]==back) nums.pop_back();
        dfs(res,nums,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> now;
        sort(nums.begin(),nums.end());
        dfs(res,nums,now);
        return res;
    }
};