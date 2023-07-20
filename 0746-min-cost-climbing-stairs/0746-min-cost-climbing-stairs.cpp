class Solution {
public:
    int solve(int n,vector<int>&cost,vector<int>&dp){
        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
    int solve2(int n,vector<int>& cost){
        int prev1 = cost[1],prev2 = cost[0];
        for(int i=2; i<n; i++){
            int temp  = cost[i] + min(prev1,prev2);
            prev2 = prev1; prev1 = temp;
        }
        return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); 
        // vector<int>dp(n+1);
        // dp[0]=cost[0],dp[1]=cost[1];
        return solve2(n,cost);
    }
};