class Solution {
    int dev = 1e9+7;
    vector<vector<vector<int>>> dp;
    int helper(int n, int needProfit, vector<int>& group, vector<int>& profit, int k) {
        if (n < 0) return 0;
        if (k == group.size()) return needProfit == 0;
        if (dp[n][needProfit][k] >= 0) return dp[n][needProfit][k];
        long res = 0;
        res += helper(n, needProfit, group, profit, k+1);
        res += helper(n - group[k], max(needProfit - profit[k],0), group, profit, k+1);
        dp[n][needProfit][k] = res % dev;
        return dp[n][needProfit][k];
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        dp = vector<vector<vector<int>>> (n+1, vector<vector<int>> (minProfit+1 , vector<int> (group.size(), -1)));
        return helper(n, minProfit, group, profit, 0);
    }
};