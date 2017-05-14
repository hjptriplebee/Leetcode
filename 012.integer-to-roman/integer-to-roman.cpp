class Solution {
public:
    string intToRoman(int num) 
    {
        string table[4][11]={
            {"", "I","II","III","IV","V","VI","VII","VIII","IX"},
            {"", "X", "XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"", "M", "MM","MMM"}
        };
        string result = "";  
        int now=0;  
        while (num > 0) 
        {  
            result=table[now][num%10]+result;
            num/=10;  
            now++;  
        }  
        //reverse(result.begin(),result.end());
        return  result;
    }
};