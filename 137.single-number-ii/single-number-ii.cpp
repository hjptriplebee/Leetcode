class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0 ; i < 32; i++)
        {
            int cnt = 0 ;
            for(int j  = 0; j < nums.size() ;j++)
            {
                cnt += ((1 << i) & nums[j])>>i;
            }
            res |= cnt % 3 << i;
            //cout<<cnt<<" "<<i<<endl;
        }
        return res;
    }
};