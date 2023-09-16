class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int dist[n][m];
        for(int i =0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                dist[i][j] = INT_MAX;
            }
        }
        priority_queue<pair<int , pair<int, int>>, vector<pair<int, pair<int, int>>>,  greater<pair<int, pair<int, int>>>> pq;
       int delrow[4] ={-1, 0, 1, 0};
       int delcol[4] = {0, 1, 0, -1};
     pq.push({0, {0, 0}});
      dist[0][0] =0;
     while(!pq.empty()) {
         int diff = pq.top().first;
         int row = pq.top().second.first;
         int col = pq.top().second.second;
          
          pq.pop();
          for(int i =0; i<4; i++) {
              int nrow = row + delrow[i];
              int ncol = col + delcol[i];
              if(nrow >=0 && nrow <n && ncol >=0 && ncol <m) {
                  int min_diff = max(abs(heights[row][col] - heights[nrow][ncol]), diff);
                  if(min_diff < dist[nrow][ncol]) {
                      dist[nrow][ncol] = min_diff;
                       pq.push({min_diff, {nrow, ncol}});
                  }
                 
              }
          }
     }

     return dist[n-1][m-1];

    }
};