class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add=1;
        for(int i=digits.size()-1;i>=0;i--)
        {
             digits[i]=(digits[i]+add)%10;
             if(digits[i]!=0) break;
        }
        if(digits[0]==0) digits.insert(digits.begin(),1);
        return digits;
    }
};