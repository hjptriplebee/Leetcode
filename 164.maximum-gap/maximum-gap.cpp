class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int minn = INT_MAX;
        int maxx = INT_MIN;
        for(int i = 0; i<nums.size(); i++)
        {
            minn = min(minn, nums[i]);
            maxx = max(maxx, nums[i]);
        }
        double len = (maxx - minn)*1.0 / (nums.size() - 1);
        if(len == 0) return 0;
        int cnt = floor((maxx - minn) / len + 1);
        vector<int> minb(cnt, INT_MAX);
        vector<int> maxb(cnt, INT_MIN);
        for(int i = 0;i<nums.size();i++)
        {
            int id = floor((nums[i] - minn) / len);
            minb[id] = min(minb[id], nums[i]);
            maxb[id] = max(maxb[id], nums[i]);
        }
        int res = 0, premax = maxb[0];
        for(int i = 1;i<cnt; i++)
        {
            if(minb[i] != INT_MAX)
            {
                res = max(res, minb[i] - premax);
                premax = maxb[i];
            }
        }
        return res;
    }
};