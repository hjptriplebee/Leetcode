class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int result=0,d=INT_MAX;
        for(int i=0;i<(int)nums.size()-2;i++)
        {
            if(i!=0 && nums[i]==nums[i-1])continue;
            int l=i+1,r=(int)nums.size()-1;
            while(l<r)
            {
                int com=(nums[i]+nums[l]+nums[r]);
                if(com<=target)
                {
                    l++;
                   // while(l<r && nums[l]==nums[l-1]) l++;
                    if(target-com<d)
                    {
                        d=target-com;
                        result=com;
                    }
                }
                else
                {
                    r--;
                   // while(l<r && nums[r]==nums[r+1]) r--;
                    if(com-target<d)
                    {
                        d=com-target;
                        result=com;
                    }
                }
            }
        }
        return result;
    }
};