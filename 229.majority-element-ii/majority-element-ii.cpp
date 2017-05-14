class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a, b, c1 = 0, c2 = 0;
        for(auto now : nums)
        {
            if(now == a) c1++;
            else if(now == b) c2++;
            else if(c1 == 0) a = now, c1 = 1;
            else if(c2 == 0) b = now, c2 = 1;
            else c1--, c2--;
        }
        c1 = c2 = 0;
        for(auto now : nums)
        {
            if(now == a) c1++;
            else if(now == b) c2++;
        }
        vector<int> res;
        if(c1 > nums.size() / 3) res.push_back(a);
        if(c2 > nums.size() / 3) res.push_back(b);
        return res;
    }
};