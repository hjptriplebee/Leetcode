class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        int limit=INT_MAX;
        for(int i=0;i<strs.size();i++)
        {
            int len=strs[i].length();
            limit=min(INT_MAX,len);
        }
        if(limit==INT_MAX) return "";
        for(int i=0;i<limit;i++)
        {
            for(int j=0;j<strs.size();j++)
                if(strs[j][i]!=strs[0][i])
                    return result;
            result+=strs[0][i];
        }   
        return result;
    }
};