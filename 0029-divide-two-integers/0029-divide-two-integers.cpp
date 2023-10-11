class Solution {
public:
    int divide(int dividend, int divisor) {
        if(0 == dividend){
            return 0;
        }
        if(divisor == INT_MIN){
            return ((divisor == dividend)?1:0);
        }
        
        int rem = 0;
        if(INT_MIN == dividend){
            rem = -1;
            dividend += 1;
        }
        bool dividend_sign = (0 > dividend);
        bool divisor_sign = (0 > divisor);
        
        int DIVISOR_MAX = INT_MAX/2;
        if(abs(divisor) >= DIVISOR_MAX){
            if((abs(dividend)>=abs(divisor)) && 
               ((dividend >= DIVISOR_MAX) || (dividend <= -DIVISOR_MAX))){
                if(((divisor > 0)&&(dividend >0)) || ((divisor < 0)&&(dividend <0))) {
                    return 1;
                }
                else{
                    return -1;
                }
            }
            else{
                return 0;
            }
        }
        
        vector<int>tmp = div(abs(dividend), abs(divisor));
        if(rem){
            rem -= tmp[1];
            vector<int>tmp_1 = div(abs(rem), abs(divisor));
            if(INT_MAX > tmp[0]){
                tmp[0] += tmp_1[0];
            }
            else{
                if((!dividend_sign && divisor_sign) || (dividend_sign && !divisor_sign)){
                    return INT_MIN;
                }
                else{
                    return INT_MAX;
                }
            }
        }
        int quo = tmp[0];
        if((!dividend_sign && divisor_sign) || (dividend_sign && !divisor_sign)){
            quo = -quo;
        }
        return quo;
    }
    
    vector<int> div(int dividend, int divisor){
        int quo = 0;        
        while(dividend >= divisor){
            int tmp_divisor = divisor;
            int tmp_divisor_1 = (tmp_divisor << 1);
            int tmp_quo = 1;
            while((tmp_divisor_1>0) && (dividend >= tmp_divisor_1)){
                tmp_divisor = tmp_divisor_1;
                tmp_divisor_1 <<= 1;
                tmp_quo <<= 1;
            }
            quo += tmp_quo;
            dividend -= tmp_divisor;
        }
        int rem = dividend;
        return {quo, rem};
    }
};