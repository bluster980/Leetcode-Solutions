class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int step = 0;
        while(left!=right){
            left >>= 1;
            right >>= 1;
            step++;
        }
        return (right << step);
    }
};