class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int mod = 1e9 + 7;
        vector<long> dp(n, 1);
        unordered_map<int, int> indexMap;
        for (int i = 0; i < n; i++) {
            indexMap[arr[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] != 0) {
                    continue;
                }
                int val = arr[i] / arr[j];
                if (indexMap.find(val) == indexMap.end()) {
                    continue;
                }
                int index = indexMap[val];
                dp[i] += dp[j] * dp[index];
                dp[i] %= mod;
            }
        }
        long res = 0;
        for (auto val : dp) {
            res += val;
        }
        return res % mod;
    }
};