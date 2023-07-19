class Solution {
public:
    // int fibon(int n,vector<int> &dp){
        // if(n==0 || n==1) return n;
    //     dp[n] = fibon(n-1,dp)+fibon(n-2,dp);
    //     return dp[n];
    // }
    int tabu(int n,vector<int>&dp){
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int fib(int n) {
        // if(n==0 || n==1) return n;
        vector<int> dp(n+2);
        dp[0]=0,dp[1]=1;
        return tabu(n,dp);
    }
};