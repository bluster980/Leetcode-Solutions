class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if ((sum + target) % 2 == 1 || sum < target || target < -sum)
            return 0;
        int newTarget = (sum + target) / 2, n = nums.size();
        vector<int> dp(newTarget + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = newTarget; j >= nums[i]; j--)
                dp[j] += dp[j - nums[i]];
        return dp[newTarget];
    }
};