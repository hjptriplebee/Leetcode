class Solution {
public:
    string fractionToDecimal(int numerator1, int denominator1) {
        long long numerator = numerator1>0 ? numerator1 : -(long long)numerator1;
        long long denominator = denominator1>0 ? denominator1 : -(long long)denominator1;
        string res;
        stringstream s;
        s << numerator / denominator;
        s >> res;
        if((long long)numerator1 * denominator1 < 0) res='-'+res;
        numerator = numerator % denominator;
        if(numerator)
        {
            res+=".";
            unordered_map<int, int> mp;
            while(numerator)
            { 
                if(mp.find(numerator) != mp.end())
                {
                    res.insert(mp[numerator], 1, '(');
                    res += ")";
                    break;
                }
                mp[numerator] = res.size();
                numerator*=10;
                int digit = numerator / denominator;
                numerator%=denominator;
                string add;
                stringstream ss;
                ss << digit;
                ss >> add;
                res += add;
                
            }
        }
        return res;
    }
};