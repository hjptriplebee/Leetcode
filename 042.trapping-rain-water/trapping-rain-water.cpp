class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1,result=0,ml=0,mr=0;
        while(l<r)
        {
            if(height[l]<height[r])
            {
                if(height[l]<ml)
                    result+=ml-height[l];
                else
                    ml=height[l];
                l++;
            }
            else
            {
                if(height[r]<mr)
                    result+=mr-height[r];
                else
                    mr=height[r];
                r--;
            }
        }
        return result;
    }
};