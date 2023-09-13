class Solution {
public:
    int mySqrt(int x) {
        if(x > 0 && x < 4) return 1;
        int l = 1, r = x/2;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(1ll*mid*mid == x){
                return mid;
            }
            if(1ll*mid*mid > x){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l-1;
    }
};