class Solution {
public:
    bool canJump(vector<int>& nums) {
        int st=0;
        while(st<nums.size()-1)
        {
            int maxx=-1,pos;
            for(int i=1;i<=nums[st];i++)
            {
                if(i+nums[st+i]>=maxx)
                {
                    maxx=i+nums[st+i];
                    pos=i;
                }
            }
            if(maxx==-1) return false;
            st+=pos;
        }
        return true;
    }
};