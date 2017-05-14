class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2) return ;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                reverse(nums.begin()+i,nums.end());
                vector<int>::iterator it=upper_bound(nums.begin()+i,nums.end(),nums[i-1]);
                swap(*it,nums[i-1]);
                return ;
            }
        }
        reverse(nums.begin(),nums.end());
    }
};