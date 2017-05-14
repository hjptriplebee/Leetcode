class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        unordered_map<char, int> mp, mp2;
        for(int i = 0; i < secret.size(); i++)
        {
            if(secret[i] == guess[i]) A++;
            else 
            {
                mp[secret[i]]++;
                mp2[guess[i]]++;
            }
        }
        for(auto k : mp)
        {
            B += min(k.second, mp2[k.first]);
        }
        
        return to_string(A) + "A" + to_string(B) + "B";
    }
};