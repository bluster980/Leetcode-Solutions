class Solution {
public:
    bool isPowerOfFour(int n) {
        int count = 0;
        if(n==INT_MIN || n<4 && n!=1 ) return false;
        bool ans = false;
        for(int i=0; i<32; i++){
            if(n & (1<<i)){
                if(!(i%2)){
                    ans = true;
                }
                count++;
            }
            //     count++;
            // if(n & (1<<i) && i%2==0){
            //     ans = true;
            // }
        }
        return (count==1)?ans:false;
    }
};