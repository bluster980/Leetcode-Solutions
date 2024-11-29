class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        bool flag1 = false,flag0 = false;
        if(grid[0][1] != 1 && grid[1][0] != 1) flag1 = true;
        if(grid[0][1] != 0 && grid[1][0] != 0) flag0 = true;

        if(flag1 && flag0) return -1;

        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        while(!pq.empty()){
            auto top = pq.top();
            int time = top.first;
            int r = top.second.first;
            int c = top.second.second;
            pq.pop();
            if(r == m-1 && c == n-1) return time;

            for(int i = 0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if(nrow < m && nrow >= 0 && ncol < n && ncol >= 0){
                    if(time + 1 >= grid[nrow][ncol] && time + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = time+1;
                        pq.push({time+1,{nrow,ncol}});
                    }
                    else if(grid[nrow][ncol] > time + 1){
                        int diff = grid[nrow][ncol] - time;
                        if(diff % 2 == 0){
                            pq.push({time + diff + 1,{nrow,ncol}});
                        }
                        else{ 
                            pq.push({time + diff,{nrow,ncol}});
                        }
                    }
                }
            }
        }

        return -1;
    }
};