class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int totalSum = 0;
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }
    
        if (totalSum == 0) {
            return 0;
        }
        int remainderToRemove = totalSum;
        unordered_map<int, int> prefixMod;
        prefixMod[0] = -1;  
        int prefixSum = 0;
        int minLen = n;
        for (int i = 0; i < n; ++i) {
            prefixSum = (prefixSum + nums[i]) % p;
            int target = (prefixSum - remainderToRemove + p) % p;
            if (prefixMod.find(target) != prefixMod.end()) {
                minLen = min(minLen, i - prefixMod[target]);
            }
            prefixMod[prefixSum] = i;
        }
        return (minLen == n) ? -1 : minLen;
    }


};