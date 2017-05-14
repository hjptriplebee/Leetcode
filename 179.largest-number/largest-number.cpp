class Solution {
public:
    static bool cmp(string &a, string &b)
    {
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) 
    {
        vector<string> res;
        for(int i = 0; i < nums.size(); i++)
            res.push_back(to_string(nums[i]));
        sort(res.begin(), res.end(), cmp);
        string ans;
        for(int i = 0; i < res.size() ; i++)
            ans += res[i];
        if(ans[0] == '0') ans = '0';
        return ans;
    }
};