class Solution {
public:
    bool dfs(int vertex,vector<int> g[],vector<bool> &vis,vector<bool> &dfsVis){
        vis[vertex] = true; dfsVis[vertex] = true;
        bool isLoopExist = false;
        for(auto child:g[vertex]){
            if(vis[child] && dfsVis[child]) return true;
            if(!vis[child])
                isLoopExist |= dfs(child,g,vis,dfsVis);
        }
        dfsVis[vertex] = false;
        return isLoopExist;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prp) {
        vector<int> g[numCourses]; vector<bool> vis(numCourses,false),dfsVis(numCourses,false);
        for(int i=0; i<prp.size(); i++){
            g[prp[i][0]].push_back(prp[i][1]);
        }
        bool isLoopExist = false;
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                isLoopExist |= dfs(i,g,vis,dfsVis);
            }
        }
        return !isLoopExist;
    }
    
};