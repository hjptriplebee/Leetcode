class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        for(int i=0,k,l;i<words.size();i+=k)
        {
            for(k=l=0;i+k<words.size() && l+words[i+k].size()<=maxWidth-k;k++) 
                l+=words[i+k].size();
            string temp=words[i];
            for(int j=0;j<k-1;j++)
            {
                if(i+k>=words.size()) 
                    temp+=' ';
                else
                    temp+=string((maxWidth-l)/(k-1)+(j<(maxWidth-l)%(k-1)),' ');
                temp+=words[i+j+1];
            }
            
            temp+=string(maxWidth-temp.size(),' ');
            result.push_back(temp);
        }
        return result;
    }
};