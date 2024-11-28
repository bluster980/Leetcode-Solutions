class Solution {
public:
    int minimumObstacles(vector<vector<int>>& g) {
        int m= g.size(),n=g[0].size();
        vector<vector<int>> dist(m,vector<int> (n,INT_MAX));
        dist[0][0]=g[0][0];
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            auto [i,j]= q.front();
            q.pop();
            if(i-1>=0 && dist[i-1][j]>dist[i][j]+g[i-1][j]){
                dist[i-1][j]=dist[i][j]+g[i-1][j];
                q.push({i-1,j});
            }
            if(j+1<n && dist[i][j+1]>dist[i][j]+g[i][j+1]){
                dist[i][j+1]= dist[i][j]+g[i][j+1];
                q.push({i,j+1});
            }
            if(i+1<m && dist[i+1][j]>dist[i][j]+g[i+1][j]){
                dist[i+1][j]= dist[i][j]+g[i+1][j];
                q.push({i+1,j});
            }
            if(j-1>=0 && dist[i][j-1]>dist[i][j]+g[i][j-1]){
                dist[i][j-1]=dist[i][j]+g[i][j-1];
                q.push({i,j-1});
            }
        }
        return dist[m-1][n-1];
    }
};