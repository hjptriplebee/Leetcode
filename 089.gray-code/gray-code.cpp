class Solution {  
public:  
    vector<int> grayCode(int n) {  
        if (n == 0)  
            return vector<int>(1, 0);  
            vector<int> pre_result = grayCode(n - 1);  
            vector<int> cur_result(pre_result);  
            for (int i = pre_result.size() - 1; i >=0; --i) {  
                cur_result.push_back((1<<(n - 1)) + pre_result[i]);  
            }  
            return cur_result;  
    }  
};