class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0) return 0;
        vector<int> x(1,-2),y(1,1);
        heights.push_back(-1);
        int result=0;
        for(int i=0;i<heights.size();i++)
        {
            int temp=1;
            while(x[x.size()-1]>=heights[i])
            {
                result=max(result,x[x.size()-1]*(y[x.size()-1]+temp-1));
                temp+=y[x.size()-1];
                x.pop_back();
                y.pop_back();
            }
            x.push_back(heights[i]);
            y.push_back(temp);
        }
        return result;
    }
};