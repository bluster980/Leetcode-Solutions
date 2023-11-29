class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for(int i=0; i<32; i++){
            bool x = (n & (1<<i));
            count+=x;
        }
        return count;
    }
};