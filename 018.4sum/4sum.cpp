class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int len=(nums.size()-3);
        for(int i=0;i<len;i++)
        {
            if(i!=0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<(len+1);j++)
            {
                if(j!=i+1 && nums[j]==nums[j-1])continue;
                int l=j+1,r=nums.size()-1;
                while(l<r)
                {
                    int com=nums[i]+nums[j]+nums[l]+nums[r];
                    if(com>target)
                        r--;
                    else if(com<target)
                        l++;
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l<r && nums[l]==nums[l+1]) l++;
                        while(l<r && nums[r]==nums[r-1]) r--;
                        r--;
                        l++;
                    }
                }
            }
        }
        return result;
    }
};