class Solution {
public:
    int bfs(int n, vector<vector<int>> &g){
        int node =0;
        vector<int> vis(n,0);
        queue<pair<int,int>> q;
        q.push({node,0});

        while(!q.empty()){
            int b = q.size();
            for(int i=0;i<b;i++){
                int currnode = q.front().first;
                int dist = q.front().second;
                q.pop();
                for(auto it:g[currnode]){
                    if(it==n-1){
                        return dist+1;
                    }
                    else if(!vis[it]){
                        vis[it]=1;
                        q.push({it,dist+1});
                    }
                }
            }
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> grid(n);
        for(int i=0;i<n-1;i++){
            grid[i].push_back(i+1);
        }
        vector<int> ans;
        for(auto it:queries){
            grid[it[0]].push_back(it[1]);
            ans.push_back(bfs(n,grid));
        }

        return ans;
    }
};