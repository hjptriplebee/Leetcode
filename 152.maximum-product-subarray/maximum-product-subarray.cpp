class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int res = nums[0];
        int minn = nums[0];
        int maxx = nums[0];
        for(int i = 1; i< nums.size();i++)
        {
            int x = maxx*nums[i];
            int y = minn*nums[i];
            maxx = max(max(x, y), nums[i]);
            minn = min(min(x, y), nums[i]);
            res = max(res, maxx);
        }
        return res;
    }
};