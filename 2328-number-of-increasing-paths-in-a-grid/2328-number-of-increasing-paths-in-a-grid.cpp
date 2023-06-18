class Solution {
public:
    int countPathsHelper(int i, int j, vector<vector<int>>& grid, int prev, vector<vector<int>>& dp) {
        
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] <= prev) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int left = countPathsHelper(i - 1, j, grid, grid[i][j], dp);
        int right = countPathsHelper(i + 1, j, grid, grid[i][j], dp);
        int up = countPathsHelper(i, j - 1, grid, grid[i][j], dp);
        int down = countPathsHelper(i, j + 1, grid, grid[i][j], dp);
        
        return dp[i][j] = (1 + left + right + up + down) % 1000000007;
        
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(), -1));
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                ans = (ans + countPathsHelper(i, j, grid, -1, dp)) % 1000000007;
            }
        }
        return ans;
    }
};