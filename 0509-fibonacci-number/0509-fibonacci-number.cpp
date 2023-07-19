class Solution {
public:
    // int fibon(int n,vector<int> &dp){
        // if(n==0 || n==1) return n;
    //     dp[n] = fibon(n-1,dp)+fibon(n-2,dp);
    //     return dp[n];
    // }
    int tabu(int n){
        int prev1=1,prev2=0;
        for(int i=2; i<=n; i++){
            int temp = prev1+prev2;
            prev2=prev1; prev1=temp;
        }
        return prev1+prev2;
    }
    int fib(int n) {
        if(n==0 || n==1) return n;
         //to avoid dp[1] when n is zero we have used n+2.
        return tabu(n-1);
    }
};