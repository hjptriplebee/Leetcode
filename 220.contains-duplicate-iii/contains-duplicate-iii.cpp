class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, long long t) {
        set<long long> s;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > k) s.erase(nums[i - k - 1]);
            set<long long>::iterator pos = s.lower_bound(nums[i] - t);
            //cout<<*pos<<endl;
            if(pos != s.end() && *pos - nums[i] <= t) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};