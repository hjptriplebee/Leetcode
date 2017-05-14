class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,int> mp;
        int cnt=0;
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            if(mp.find(temp)==mp.end())
            {
                vector<string> s;
                s.push_back(strs[i]);
                result.push_back(s);
                mp[temp]=cnt++;
            }
            else
            {
                result[mp[temp]].push_back(strs[i]);
            }
        }
        return result;
    }
};