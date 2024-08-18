class Solution {
public:
    
    int nthUglyNumber(int n) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<int>dp(n+1);
        dp[1] = 1;
        int p2 = 1;
        int p3 = 1;
        int p5 = 1;
        for(int i=2; i<=n; i++){
            int f1 = 2*dp[p2];
            int f2 = 3*dp[p3];
            int f3 = 5*dp[p5];
            int mini = min(f1,min(f2,f3));
            dp[i] = mini;
            if(f1==mini) p2++;
            if(f2==mini) p3++;
            if(f3==mini) p5++;
        }
        return dp[n];
    }
};