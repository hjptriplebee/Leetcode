/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(const struct Interval &a,const struct Interval &b)
    {
        if(a.start!=b.start)
            return a.start<b.start;
        return a.end<b.end;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<int> test;
        sort(intervals.begin(),intervals.end(),cmp);//注意这里的cmp写在类内，需要是static的
        vector<Interval> result;
        for(int i=0;i<intervals.size();)
        {
            Interval temp=intervals[i];
            i++;
            while(i<intervals.size() && temp.end>=intervals[i].start)
                temp.end=max(temp.end,intervals[i++].end);
            result.push_back(temp);
        }
        return result;
    }
};