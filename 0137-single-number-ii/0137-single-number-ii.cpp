class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int oneCounter = 0;
        int twoCounter = 0;
        
        for (int &n : nums) {
            oneCounter = (oneCounter ^ n) & ~twoCounter;
            twoCounter = (twoCounter ^ n) & ~oneCounter;
        }
        
        return oneCounter;
    }
};