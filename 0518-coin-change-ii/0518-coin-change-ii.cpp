class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[5001] = {1};
        for(auto x:coins){
            for(int i=x; i<=amount; i++){
                dp[i] += dp[i - x];
            }
        }
        return dp[amount];
    }
};