class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = 0, l = 0, r = 0;
        int ans = INT_MAX;
        while(r <= nums.size())
        {//cout<<l<<" "<<r<<endl;
            if(res >= s) 
            {
                ans = min(ans, r - l);
                res -= nums[l++];
            }
            else
            {
                if(r == nums.size()) break;
                res += nums[r++];
            }
                
        }
        return ans == INT_MAX ? 0 : ans;
    }
};