class Solution {
public:
    int helper(int amount,vector<int> &coins,vector<int> &dp){
        if(dp[amount] == 0) return 0; 
        if(dp[amount] != -1) return dp[amount];
        
        int ans = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            if(amount-coins[i] >= 0)
                ans = min(ans+0ll,helper(amount-coins[i],coins,dp)+1ll);
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(10010,-1); dp[0]=0;
        int ans = helper(amount,coins,dp);
        return (ans==INT_MAX)?-1:ans;
    }
};

