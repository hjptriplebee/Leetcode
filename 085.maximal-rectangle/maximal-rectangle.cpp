class Solution {
public:
    int largestRectangleArea(vector<int> heights) {  
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int result=0;
        if(matrix.size()==0) return 0; 
        vector<int> temp(matrix[0].size(),0);
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
                temp[j]=matrix[i][j]-'0'==0?0:temp[j]+1;
            result=max(result,largestRectangleArea(temp));
        }
        return result;
    }
};