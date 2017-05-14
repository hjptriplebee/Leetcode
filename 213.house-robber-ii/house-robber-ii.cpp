class Solution {
public:
    int rob(vector<int>& nums) {
        int a1 = 0;
        int b1 = 0;
        int a2 = 0;
        int b2 = 0;
        if(nums.size() == 1) return nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            if(i != nums.size() - 1)
            {
                if(i & 1) a1 = max(a1 + nums[i], b1);
                else b1 = max(b1 + nums[i], a1);
            }
            if(i != 0)
            {
                if(i & 1) a2 = max(a2 + nums[i], b2);
                else b2 = max(b2 + nums[i], a2); 
            }
        }
        return max(max(a1, b1), max(a2, b2));
        
    }
};