class Solution {
public:
    int f(int i, int canBuy, vector<int> &prices, vector<vector<int>> &dp) {
        return i >= prices.size() ? 0 : dp[i][canBuy] == -1 ? dp[i][canBuy] = canBuy ? max(-prices[i] + f(i+1, 0, prices, dp), f(i+1, 1, prices, dp)) : max(prices[i] + f(i+2, 1, prices, dp), f(i+1, 0, prices, dp)) : dp[i][canBuy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return f(0, 1, prices, dp);
    }
};