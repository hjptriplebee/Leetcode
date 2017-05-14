class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int result=0;
        if(nums.size()>0) result=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1]) 
                result++;
            else
            {
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return result;
    }
};