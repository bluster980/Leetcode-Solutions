class Solution {
public:
    int fibon(int n,vector<int> &dp){
        if(n==0 || n==1) return n;
        dp[n] = fibon(n-1,dp)+fibon(n-2,dp);
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n+1);
        return fibon(n,dp);
    }
};