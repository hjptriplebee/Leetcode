class Solution {
public:
    int jump(vector<int>& nums) {
        int st=0,result=0;
        while(st<nums.size()-1)
        {
            if(st+nums[st] >= nums.size()-1) return result+1;
            int maxx=0,pos=0;
            for(int i=1;st+i<=nums.size() && i<=nums[st];i++)
            {
                if(i+nums[st+i]>=maxx)
                {
                    maxx=i+nums[st+i];
                    pos=i;
                }
            }
            st+=pos;
            result++;
        }
        return result;
    }
};