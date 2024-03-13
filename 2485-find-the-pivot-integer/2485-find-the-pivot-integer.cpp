class Solution {
public:
    int pivotInteger(int n) {
        int temp = n*(n+1)/2;
        int curr = 0;
        for(int i=n; i>0; i--){
            curr += i;
            if(curr == temp) return i;
            temp -= i;
        }
        return -1;
    }
};