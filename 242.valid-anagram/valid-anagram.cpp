class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26] = {0};
        for(auto c : s) cnt[c - 'a']++;
        for(auto c : t) cnt[c - 'a']--;
        for(auto c : cnt) if(c) return false;
        
        
        
        return s.size() != t.size() ? false : true;  
    }
};