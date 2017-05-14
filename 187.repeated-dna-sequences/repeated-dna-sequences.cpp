class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.size() < 10) return res;
        unordered_map<int, int> mp;
        unordered_map<char, int> id;
        id['A'] = 0;
        id['C'] = 1;
        id['G'] = 2;
        id['T'] = 3;
        int temp = 0;
        for(int i = 0; i < s.size(); i++)
        {
            temp = (temp<<2| (id[s[i]] & 3)) & 0xfffff;
            if(i > 8)
            {
                if(mp[temp] == 1) res.push_back(s.substr(i - 9,10));
                mp[temp]++;
            }
        }
        
        
        
        return res;
    }
};