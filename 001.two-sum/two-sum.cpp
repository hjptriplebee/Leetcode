class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> result;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=i+1;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mp[target-nums[i]]>(i+1) )
            {
                //cout<<i<<" "<<mp[target-nums[i]]-1<<endl;
                result.push_back(i);
                result.push_back(mp[target-nums[i]]-1);
                break;
            }
        }
        return result;
    }
};