class Solution {
public:
    string countAndSay(int n) {
        string result="1";
        for(int i=1;i<n;i++)
        {
            string temp;
            for(int j=0;j<result.length();j++)
            {
                int cnt=1;
                while(j<result.length()-1 && result[j]==result[j+1])
                {
                    cnt++;
                    j++;
                }
                
                temp+=to_string(cnt)+result[j];
            }
            result=temp;
        }
        return result;
    }
};