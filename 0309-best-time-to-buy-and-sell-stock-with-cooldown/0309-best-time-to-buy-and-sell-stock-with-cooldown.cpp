class Solution {
public:
    int memo[5005][1105];
    int dp(int i, int buy, vector<int>& prices){
        if (i >= prices.size())
            return 0;

        int& ans = memo[i][buy];
        if (~ans) return ans;
        
        ans = dp(i+1, buy, prices);
        if (buy == 1100)
            ans = max(ans, dp(i+1, prices[i], prices));
        else 
            ans = max(ans,(-buy + prices[i]) + dp(i+2, 1100, prices));

        return ans;
    }

    int maxProfit(vector<int>& prices) {
        memset(memo, -1, sizeof memo);
        return dp(0, 1100, prices);
    }
};