class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> mp;
        vector<int> result;
        unordered_map<string, int>::iterator it;
        int len=words[0].length(),num=words.size();
        for(int i=0;i<len;i++) //起点
        {
            for(int i=0;i<num;i++)
                mp[words[i]]++;
            int st=i,cnt=0;
            for(int j=i;j<s.length();j+=len) 
            {
                string now=s.substr(j,len);
                it=mp.find(now); //不用迭代器直接比较，下面第二个判断条件会出问题？
                if(mp.find(now)!=mp.end()) //这里的it是在mp[now]访问之前获得的
                {
                    if(mp[now]>0) //这里访问了mp[now],所以即使now不存在，在经过这次访问后也就存在了
                    {
                        mp[now]--;
                        if(++cnt==num)
                        {
                            result.push_back(st);
                            mp[s.substr(st,len)]++;
                            st+=len;
                            cnt--;
                        }
                    }
                    else
                    {
                        for(int k=st;k<j;k+=len)
                        {
                            if(s.substr(k,len)==now)
                            {
                              st=k+len;
                              break;
                            }
                            else
                            {
                                mp[s.substr(k,len)]++;
                                cnt--;
                            }
                        }
                    }
                }
                else
                {
                    for(int k=st;k<j;k+=len)
                        mp[s.substr(k,len)]++;
                    st=j+len;
                    cnt=0;
                }
            }
            mp.clear();
        }
        return result;
    }
};