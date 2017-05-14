class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(nums[l]>nums[r])
        {
            int mid = (l + r) >> 1;
            if(nums[mid] >= nums[l]) 
                l = mid+1;
            else  
                r = mid; 
        }
        return nums[l];
    }
};