class Solution {
public:
    int compareVersion(string version1, string version2) {
        if(version1.empty() && version2.empty()) return 0;
        if(version1.empty()) version1+="0";
        if(version2.empty()) version2+="0";
        int index1 = version1.find(".");
        int index2 = version2.find(".");
        int v11 = index1 == -1 ? stoi(version1) : stoi(version1.substr(0, index1));
        int v21 = index2 == -1 ? stoi(version2) : stoi(version2.substr(0, index2));
        if(v11 > v21) return 1;
        else if(v11 < v21) return -1;
        else
        {
            string s1, s2;
            if(index1 != -1) s1 = version1.substr(index1+1); 
            if(index2 != -1) s2 = version2.substr(index2+1);
            return compareVersion(s1, s2);
        }

    }
};