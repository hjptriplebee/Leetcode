class Solution {
public:
    int hIndex(vector<int>& citations) {
        int mid = -1, l = 0, r = citations.size()-1;
        while(l <= r)
        {
            mid = (l + r) >> 1;
            if(citations.size() - mid == citations[mid]) return citations[mid];
            else if(citations.size() - mid > citations[mid]) l = mid + 1;
            else r = mid - 1;
        }
        return citations.size() - r - 1;
    }
};
