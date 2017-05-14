class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i = 0; i < input.size(); i++)
        {
            if(input[i] == '+')
            {
                for (int a : diffWaysToCompute(input.substr(0, i)))
                    for (int b : diffWaysToCompute(input.substr(i+1)))
                        res.push_back(a + b);
            }
            else if(input[i] == '-')
            {
                for (int a : diffWaysToCompute(input.substr(0, i)))
                    for (int b : diffWaysToCompute(input.substr(i+1)))
                        res.push_back(a - b);
            }
            else if(input[i] == '*')
            {
                for (int a : diffWaysToCompute(input.substr(0, i)))
                    for (int b : diffWaysToCompute(input.substr(i+1)))
                        res.push_back(a * b);
            }
        }
        if(res.empty()) res.push_back(stoi(input));
        return res;
    }
};