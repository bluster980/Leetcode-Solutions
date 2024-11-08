class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int>ans(n); 

        int xor1 = 0;

        int k = pow(2,maximumBit)-1;

        for(auto i : nums)
        {
            xor1^=i;
        }

        int a = 0;

        for(int i=0;i<n;i++)
        {
             ans[i] = xor1 ^ k;
             xor1 ^= nums[n - 1 - i];

        }
        return ans;
    }
};