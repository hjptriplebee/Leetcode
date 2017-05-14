class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) return res;
        int s = nums[0], e = nums[0]; 
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 1] + 1) e = nums[i];
            else
            {
                if(s == e) res.push_back(to_string(s));
                else res.push_back(to_string(s) + "->" + to_string(e));
                s = e = nums[i];
            }
        }
        if(s == e) res.push_back(to_string(s));
        else res.push_back(to_string(s) + "->" + to_string(e));
        return res;
    }
};