class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitset(32,0);
        for(int &n:nums) {
            int mask = 0;
            while(mask<32) {
                if((n&(1<<mask))) {
                    bitset[mask]++;
                }
                mask++;
            }
        }
        int nm  = 0;
        for(int i = 0; i < 32; i++) {
            if(bitset[i]%3) {
                nm |= (1 <<i);
            }   
        }
        return nm;
    }
};