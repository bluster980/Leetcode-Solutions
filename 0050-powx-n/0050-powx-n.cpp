class Solution {
public:    
    double myPow(double x, int n) {
        // if(n<0){
        //     x = 1/x;
        // }
        // double ans = 1;
        // while(n){
        //     if(n&1){
        //         ans *= x;
        //     }
        //     n>>=1; x = (x*x);
        // }
        return pow(x,n);
    }
};