class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int e1=m-1,e2=n-1,e3=m+n-1;
        while(e1>=0 || e2>=0)
        {
            if(e1==-1) 
                nums1[e3--]=nums2[e2--];
            else if(e2==-1)
                nums1[e3--]=nums1[e1--];
            else if(nums1[e1]>nums2[e2])
                nums1[e3--]=nums1[e1--];
            else
                nums1[e3--]=nums2[e2--];
        }
    }
};