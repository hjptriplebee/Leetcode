class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int s = 1, e = 1;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            res[i] *= s;
            s *= nums[i];
            res[n - 1 - i] *= e;
            e *= nums[n - 1 - i];
        }
        return res;
    }
};