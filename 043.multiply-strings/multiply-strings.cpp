class Solution {
public:
    string multiply(string num1, string num2) {
        string result;
        if(num1.size()==0 || num2.size()==0)
            return "";
        int flag=1;
        if(num1[0]=='-') flag=-flag;
        if(num2[0]=='-') flag=-flag;
        vector<int> cnt(num1.size()+num2.size()+1,0);
        if(num1.size()>num2.size()) swap(num1,num2);
        for(int i=num1.size()-1;i>=0;i--)
        {
            if(num1[i]=='-') break;
            for(int j=num2.size()-1;j>=0;j--)
            {
                if(num2[i]=='-') break;
                int t=(num1[i]-'0')*(num2[j]-'0')+cnt[i+j+2];
                cnt[i+j+2]=t%10;
                cnt[i+j+1]+=t/10;
                //cout<<cnt[i+j+1]<<" "<<cnt[i+j+2]<<endl;
            }
        }
        int i=0;
        while(cnt[i]==0) i++;
        for(;i<cnt.size();i++)
        {
            result+=(cnt[i]+'0');
        }
        if(result.size()==0) return "0";
        if(flag==-1) result="-"+result;
        return result;
    }
};