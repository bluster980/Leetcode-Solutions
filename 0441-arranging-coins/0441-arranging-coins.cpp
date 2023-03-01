class Solution {
public:
    int arrangeCoins(int n) {
        int temp = 0;
        while(n>=temp && n > 0){
            n-=temp; temp++;
        }
        return temp-1;
    }
};