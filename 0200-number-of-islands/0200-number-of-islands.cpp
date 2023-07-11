class Solution {
public:
    void dfs(pair<int,int> pr,map<pair<int,int>,bool>&vis,vector<vector<char>>& grid){
        vis[pr] = true;
        // if(vis.find(pr)==vis.end()){
            if(grid[pr.first][pr.second] == '1'){
                grid[pr.first][pr.second] = '0';
                if(pr.second-1 >= 0){
                    dfs({pr.first,pr.second-1},vis,grid);
                }
                if(pr.first-1 >= 0){
                    dfs({pr.first-1,pr.second},vis,grid);
                }
                if(pr.first+1 < grid.size()){
                    dfs({pr.first+1,pr.second},vis,grid);
                }
                if(pr.second+1 < grid[0].size()){
                    dfs({pr.first,pr.second+1},vis,grid);
                }
            }
        // }   
    }
    
//     void dfs(pair<int, int> pr, map<pair<int, int>, bool>& vis, vector<vector<char>>& grid) {
//     vis[pr] = true;
//     if (grid[pr.first][pr.second] == '1') {
//         grid[pr.first][pr.second] = '0';
//         if (pr.second - 1 >= 0) {
//             dfs({pr.first, pr.second - 1}, vis, grid);
//         }
//         if (pr.first - 1 >= 0) {
//             dfs({pr.first - 1, pr.second}, vis, grid);
//         }
//         if (pr.first + 1 < grid.size()) {
//             dfs({pr.first + 1, pr.second}, vis, grid);
//         }
//         if (pr.second + 1 < grid[0].size()) {
//             dfs({pr.first, pr.second + 1}, vis, grid);
//         }
//     }
// }

    
    int numIslands(vector<vector<char>>& grid) {
        int N = 1e4; int count = 0;
        map<pair<int,int>,bool>vis;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(vis.find({i,j})==vis.end() && grid[i][j] == '1'){
                    dfs({i,j},vis,grid); count++;
                }
            }
        }
        return count;
    }
};