class Solution {
public:
    bool wordPattern(string pattern, string str) {
        str += " ";
        int j = 0;
        unordered_map<string, string> mp;
        for(int i = 0; i < str.size(); i++)
        {
            int pos = str.find(" ", i);
            string tmp = str.substr(i, pos - i);
            i = pos;
            if(j == pattern.size()) return false;
            string key(pattern[j] + "\0");
            if(mp.find(key) == mp.end())
            {
                if(mp.find(tmp) == mp.end()) 
                {
                    mp[tmp] = key;
                    mp[key] = tmp;
                }
                else return false;
            }
            else if(mp[key] != tmp) return false;
            j++;
        }
        if(j != pattern.size()) return false;
        return true;
    }
};