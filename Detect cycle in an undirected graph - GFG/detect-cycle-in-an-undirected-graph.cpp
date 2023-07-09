//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int vertex, int parent, vector<int> g[], vector<bool> &vis){
        vis[vertex] = true;
        bool isLoopExist = false;
        for(auto child:g[vertex]){
            if(vis[child] && child == parent) continue;
            if(vis[child]) return true;
            // vis[child] = true;
            isLoopExist |= dfs(child,vertex,g,vis);
        }
        return isLoopExist;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V+1,false);
        bool isLoopExist = false;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                isLoopExist |= dfs(i,-1,adj,vis);
            }
        }
        return isLoopExist;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends