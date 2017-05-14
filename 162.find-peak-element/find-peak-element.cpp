class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l<r)
        {
            int mid = (l+r)>>1;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) return mid;
            if(nums[mid]<nums[mid+1]) l = mid+1;
            else r= mid-1;
        }
        return l;
    }
};