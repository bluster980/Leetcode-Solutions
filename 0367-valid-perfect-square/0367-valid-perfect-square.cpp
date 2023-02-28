class Solution {
public:
    bool isPerfectSquare(int num) {
        int temp = 1;
        for(int i=0; i<num; i++){
            num -= temp;
            temp+=2;
        }
        return num==0;
    }
};