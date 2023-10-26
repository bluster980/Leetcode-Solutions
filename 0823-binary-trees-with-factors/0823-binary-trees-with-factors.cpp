class Solution {
public:
    const int MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& nums) {
        unordered_map<int,long long> mp; long long ans = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size(); i++){
            long long cnt = 1;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]) continue;
                long long x = nums[j];
                long long y = nums[i]/nums[j];
                cnt = (cnt + (mp[x]*mp[y]) % MOD) % MOD;
            }
            mp[nums[i]] = cnt;
            ans = (ans + cnt) % MOD;
        }
        return (int)ans;
    }
};