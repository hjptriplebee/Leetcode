class Solution
{
public:
    double fun(vector<int> a,int sa,int ea,vector<int> b,int sb,int eb,int k)
    {
        //cout<<sa<<" "<<ea<<" "<<sb<<" "<<eb<<" "<<k<<endl; 
        if(ea+1-sa>eb+1-sb)
            return fun(b,sb,eb,a,sa,ea,k);
        if(ea+1-sa == 0)
            return b[k-1];
        if(k==1)
            return min(a[sa],b[sb]);
        int ta=min(ea+1-sa,k/2),tb=k-ta;
        //cout<<ta<<" "<<tb<<endl;
        //cout<<a[sa+ta-1]<<" "<<b[sb+tb-1]<<endl;
        if(a[sa+ta-1]==b[sb+tb-1])
            return a[sa+ta-1];
        if(a[sa+ta-1]>b[sb+tb-1])
            return fun(a,sa,ea,b,sb+tb,eb,k-tb);
        return fun(a,sa+ta,ea,b,sb,eb,k-ta);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int len1=nums1.size();
        int len2=nums2.size();
        if((len1+len2)%2)
            return fun(nums1,0,len1-1,nums2,0,len2-1,(len1+len2+1)/2);
        else
            return (fun(nums1,0,len1-1,nums2,0,len2-1,(len1+len2)/2+1)+fun(nums1,0,len1-1,nums2,0,len2-1,(len1+len2)/2))/2;
    }
};