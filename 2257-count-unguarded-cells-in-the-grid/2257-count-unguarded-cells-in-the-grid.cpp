class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        int cnt = 0;
        for(auto gs : guards) {
            grid[gs[0]][gs[1]] = 1;
        }
        for(auto ws : walls) {
            grid[ws[0]][ws[1]] = -1;
        }

        for(int i=0; i<m; i++) {
            bool guarded = false;
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) guarded = true;
                else if(grid[i][j] == -1) guarded = false;
                else if(grid[i][j] == 0) grid[i][j] = guarded==true ? 2 : 0;
            }
            guarded = false;
            for(int j=n-1; j>=0; j--) {
                if(grid[i][j] == 1) guarded = true;
                else if(grid[i][j] == -1) guarded = false;
                else if(grid[i][j] == 0) grid[i][j] = guarded==true ? 2 : 0;
            }
        }

        for(int j=0; j<n; j++) {
            bool guarded = false;
            for(int i=0; i<m; i++) {
                if(grid[i][j] == 1) guarded = true;
                else if(grid[i][j] == -1) guarded = false;
                else if(grid[i][j] == 0) grid[i][j] = guarded==true ? 2 : 0;
            }
            guarded = false;
            for(int i=m-1; i>=0; i--) {
                if(grid[i][j] == 1) guarded = true;
                else if(grid[i][j] == -1) guarded = false;
                else if(grid[i][j] == 0) grid[i][j] = guarded==true ? 2 : 0;
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};