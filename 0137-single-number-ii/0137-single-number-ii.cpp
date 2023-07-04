class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> v(32,0);
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<32; j++){
                if((1<<j)&nums[i]) v[j]++;
            }
        }
        int temp = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i]%3 != 0) temp |= (1<<i);
        }
        return temp;
    }
};

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         vector<int> bitset(32,0);
//         for(int &n:nums) {
//             int mask = 0;
//             while(mask<32) {
//                 if((n&(1<<mask))) {
//                     bitset[mask]++;
//                 }
//                 mask++;
//             }
//         }
//         int nm  = 0;
//         for(int i = 0; i < 32; i++) {
//             if(bitset[i]%3) {
//                 nm |= (1 <<i);
//             }   
//         }
//         return nm;
//     }
// };