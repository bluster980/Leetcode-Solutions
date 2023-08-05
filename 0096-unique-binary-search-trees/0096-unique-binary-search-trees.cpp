class Solution {
public:
    // unordered_map<int,int> dp;
    // static const int n = 1e3;
    // vector<int> dp(n);
    int dp[20];
    int numTrees(int n) {
        if(n==0 || n==1) return 1;
        if(dp[n]!=0) return dp[n];
        int result = 0;
        for(int i=1; i<=n; i++){
            int l = numTrees(i-1);
            int r = numTrees(n-i);
            result += l*r;
        }
        return dp[n] = result;
    }
};