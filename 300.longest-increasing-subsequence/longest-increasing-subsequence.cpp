class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for(auto i : nums)
        {
            auto tmp = lower_bound(res.begin(), res.end(), i);
            if(tmp == res.end()) res.push_back(i);
            else *tmp = i;
        }
        return res.size();
    }
};
