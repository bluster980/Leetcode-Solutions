class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(2, vector<int> (n));
        for(int i=n-1;i>=0;i--) {
            for(int j=i;j<n;j++) {
                if(i == j){
                    continue;
                }
                dp[i&1][j] = 1 + min(dp[(i+1)&1][j], dp[i&1][j-1]);
                if(s[i] == s[j]) dp[i&1][j] = min(dp[i&1][j], dp[(i+1)&1][j-1]);
            }
        }
        return dp[0][n-1];
    }
};