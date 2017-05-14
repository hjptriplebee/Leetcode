class Solution {
public:
    int find(int x,unordered_map<int,int> &set)
    {
        if(set[x]!=x)
        set[x]=find(set[x],set);
        return set[x];
    }
    int longestConsecutive(vector<int>& nums) {
        int res=1;
        if(nums.empty()) return 0;
        unordered_map<int,int> set,dp;
        for(int i=0;i<nums.size();i++)
        {
            set[nums[i]]=nums[i];
            dp[nums[i]]=1;
        }
        for(int i=0;i<nums.size();i++)
        {
            int y,x=find(nums[i],set);
            if(set.find(nums[i]-1)!=set.end())
            {
                y=find(nums[i]-1,set);
                if(y!=x)
                {
                    dp[x]+=dp[y];
                    set[y]=x;
                }
                res=max(res,dp[x]);
            }
            if(set.find(nums[i]+1)!=set.end())
            {
                y=find(nums[i]+1,set);
                if(y!=x)
                {
                    dp[x]+=dp[y];
                    set[y]=x;
                }
                res=max(res,dp[x]);
            }
        }
        return res;
    }
};