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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
    {
        vector<Interval> result;
        sort(intervals.begin(),intervals.end(),cmp);
        int flag=0;
        for(int i=0;i<intervals.size();i++)
        {
            if(flag) 
                result.push_back(intervals[i]);
            else
            {
                if(newInterval.end<intervals[i].start)
                {
                    flag=1;
                    result.push_back(newInterval);
                    result.push_back(intervals[i]);
                }
                else 
                {
                    if(newInterval.start<=intervals[i].end)
                    {
                        flag=1;
                        intervals[i].start=min(intervals[i].start,newInterval.start);
                        intervals[i].end=max(intervals[i].end,newInterval.end);
                        int jump=1;
                        while(i+jump<intervals.size() && intervals[i+jump].start<=intervals[i].end)
                        {
                            intervals[i].end=max(intervals[i].end,intervals[i+jump].end);
                            jump++;
                        }
                        result.push_back(intervals[i]);
                        i+=jump-1;
                    }
                    else
                        result.push_back(intervals[i]);
                }
            }
            
        }
        if(!flag) result.push_back(newInterval);
        return result;
    }
};