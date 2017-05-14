class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1 = 0, p2 = 0;
        while(p1 < nums.size())
        {
            if(!nums[p1])
            {
                p2 = max(p1, p2);
                while(p2 < nums.size())
                {
                    if(nums[p2]) 
                    {
                        swap(nums[p1], nums[p2]);
                        break;
                    }
                    p2++;
                }
            }
            p1++;
        }
    }
};