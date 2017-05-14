class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;//两种溢出的情况
        int flag1=dividend<0?-1:1,flag2=divisor<0?-1:1;
        int pre=flag1==flag2?1:-1;
        long long dividend2=flag1==1?dividend:-(long long)dividend; //转正数，int类型在INT_MIN值下会炸
        long long divisor2=flag2==1?divisor:-(long long)divisor;
        int result=0;
        //cout<<flag1<<" "<<flag2<<endl;
        //cout<<dividend2<<" "<<divisor<<endl;
        while(dividend2>=divisor2) 
        {
            long long rm=divisor2,base=1;
            while(dividend2>=rm)
            {
                rm<<=1;
                base<<=1;
            }
            rm>>=1;
            base>>=1;
            dividend2-=rm;
            result+=base;
        }
        result=pre==1?result:-result; //符号
        return result;
    }
};