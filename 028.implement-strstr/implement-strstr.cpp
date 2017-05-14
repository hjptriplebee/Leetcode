class Solution {
public:
    int* getNext(string b)
    {
        int len=b.length();
        int j=0;
        int* next=new int[len+1];//next表示长度为i的字符串前缀和后缀的最长公共部分，从1开始  
        next[0]=next[1]=0;
        for(int i=1;i<len;i++)//i表示字符串的下标，从0开始  
        {
            while(j>0&&b[i]!=b[j]) j=next[j];//j在每次循环开始都表示next[i]的值，同时也表示需要比较的下一个位置  
            if(b[i]==b[j])j++;  
            next[i+1]=j;  
        }  
        return next;  
    }
    int strStr(string haystack, string needle) 
    {
        if(needle.length()==0) return 0;
        int* next=getNext(needle);
        int j=0;  
        for (int i=0;i<haystack.length();i++) 
        {  
            while (j>0 && haystack[i]!=needle[j]) j=next[j];  
            if (haystack[i]==needle[j]) j++;  
            if (j==needle.length()) 
                return i-j+1;
            cout<<i<<endl;
        }
        return -1;
    }
};