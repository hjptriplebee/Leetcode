class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.begin()+nums.size()-k);
        reverse(nums.begin()+nums.size()-k, nums.begin()+nums.size());
        reverse(nums.begin(), nums.begin()+nums.size());
    }
};