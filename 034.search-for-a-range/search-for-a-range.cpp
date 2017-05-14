class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
       // if(target<*nums.begin() || target>*(nums.end()-1))
          //  return result;
        int l=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int r=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(l!=r)
        {
            result[0]=l;
            result[1]=r-1;
        }
        //cout<<l<<" "<<r<<endl;
        return result;
    }
};