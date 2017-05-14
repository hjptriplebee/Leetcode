// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1, r = n;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(isBadVersion(mid)) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};