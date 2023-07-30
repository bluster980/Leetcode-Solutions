class Solution {
public:
    int helper(int amount, vector<int> &coins, vector<int> &dp){
        if(amount == 0) return 0; 
        if(dp[amount] != -1) return dp[amount];
        
        int ans = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            if(amount-coins[i] >= 0)
                ans = min(ans+0ll, helper(amount-coins[i], coins, dp) + 1ll);
        }
        return dp[amount] = ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0; // Base case: no coins needed to make 0 amount.
        int ans = helper(amount, coins, dp);
        // cout<<ans<<endl;
        return (ans == INT_MAX) ? -1 : ans;
    }
};
