class Solution {
public:
    int myAtoi(string str){
        long int res=0;
        int i=0;
        int sign=1;
        while(str.length()>i)
        { 
            if(i>=str.length())
                return 0;
            if(str[i]!=' ')
                break;
            i++;
        }
        if(str[i]=='-' || str[i]=='+')
            sign=str[i++]=='-'?-1:1;
        while(i<str.length() and isdigit(str[i]))
        {
            res=res*10+(str[i++]-'0');
            // i++;
            if(res*sign>=INT_MAX )return INT_MAX;
            if(res*sign<=INT_MIN )return INT_MIN;
        }
        return res*sign;
    }
     
};