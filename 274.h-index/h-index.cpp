class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> cnt(citations.size() + 2, 0);
        for(int i = 0; i < citations.size(); i++)
        {
            if(citations[i] > citations.size()) cnt[citations.size()]++;
            else cnt[citations[i]]++;
        }
        for(int i = citations.size() ; i >= 0; i--)
        {
            cnt[i] += cnt[i + 1];
            if(cnt[i] >= i) return i;
        }
        return 0;
    }
};