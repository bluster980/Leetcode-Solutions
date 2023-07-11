class Solution {
public:
    bool dfs(int vertex,int col,vector<int> g[],vector<int> &color){
        color[vertex] = col;
        bool isCol = true;
        for(auto child:g[vertex]){
            if(color[child] == col) return false;
            else if(color[child] == -1) isCol &= dfs(child,!col,g,color);
        }
        return isCol;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        vector<int> g[graph.size()];
        for(int i=0; i<graph.size(); i++){
            for(int j=0; j<graph[i].size(); j++){
                g[i].push_back(graph[i][j]);
                g[graph[i][j]].push_back(i);
            }
        }
        bool isCol = true; int col = 1;
        for(int i=0; i<graph.size(); i++){
            if(color[i] == -1){
                isCol &= dfs(i,col,g,color);
            }
        }
        return isCol;
    }
};