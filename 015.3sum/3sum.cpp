class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int len=(nums.size()-2);
        for(int i=0;i<len;i++)
        {
            //cout<<i<<" "<<nums.size()-2<<endl;
            if(nums[i]>0)continue;
            if(i!=0 && nums[i]==nums[i-1])continue;
            int l=i+1,r=nums.size()-1;
            while(l<r)
            {
                int com=nums[i]+nums[l]+nums[r];
                if(com>0)
                    r--;
                else if(com<0)
                    l++;
                else
                {
                    result.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(l<r && nums[r]==nums[r-1]) r--;
                    r--;
                    l++;
                }
            }
        }
        return result;
    }
};