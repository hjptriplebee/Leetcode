class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int result=nums.size(),pre=1;
        for(int i=1,j=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                pre++;
                if(pre>2) 
                    result--;
                else
                    nums[j++]=nums[i];
            }
            else
            {
                pre=1;
                nums[j++]=nums[i];
            }
        }
        return result;
    }
};