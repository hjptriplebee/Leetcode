/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<double, int> mp;
        int res = 0;
        for(int i = 0; i < points.size(); i++)
        {
            int re = 0, temp = 0, resp = 0;
            for(int j = i+1; j < points.size(); j++)
            {
                if(points[i].x == points[j].x)
                {
                    if(points[i].y == points[j].y) 
                        re++;
                    else
                        temp++;
                }
                else
                {
                    double k = 1.0*(points[i].y - points[j].y)/(points[i].x - points[j].x);
                    mp[k]++;
                    resp = max(resp, mp[k]);
                }
            }
            res = max(res, max(resp, temp) + re + 1);
            mp.clear();
        }
        return res;
    }
};