//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;

vector<int> minimumCut(vector<vector<int>> &A, int S, int T, int N);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> A(N,vector<int> (N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> A[i][j];
            }
        }
        int S, T;
        cin >> S >> T;
        vector<int> res = minimumCut(A, S, T, N);
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends




int bfs(vector<vector<int>> &rGraph, int s, int t, int N, vector<int> &parent) 
{ 
    // Create a visited array and mark all vertices as not visited 
    vector<bool> visited(N); 
  
    // Create a queue, enqueue source vertex and mark source vertex 
    // as visited 
    queue<int> q; 
    q.push(s); 
    visited[s] = true; 
    parent[s] = -1; 
  
    // Standard BFS Loop 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop(); 
  
        for (int v=0; v<N; v++) 
        { 
            if (visited[v]==false && rGraph[u][v] > 0) 
            { 
                q.push(v); 
                parent[v] = u; 
                visited[v] = true; 
            } 
        } 
    } 
  
    // If we reached sink in BFS starting from source, then return 
    // true, else false 
    return (visited[t] == true); 
} 

// A DFS based function to find all reachable vertices from s.  The function 
// marks visited[i] as true if i is reachable from s.  The initial values in 
// visited[] must be false. We can also use BFS to find reachable vertices 
void dfs(vector<vector<int>> &rGraph, int S, int N, vector<bool> &visited) 
{ 
    visited[S] = true; 
    for (int i = 0; i < N; i++) 
       if (rGraph[S][i] && !visited[i]) 
           dfs(rGraph, i, N, visited); 
} 

vector<int> minimumCut(vector<vector<int>> &A, int S, int T, int N){
    int u, v; 
  
    // Create a residual graph and fill the residual graph with 
    // given capacities in the original graph as residual capacities 
    // in residual graph 
    vector<vector<int>> rGraph;
    rGraph = A;
  
    vector<int> parent(N);  // This array is filled by BFS and to store path 
    
    // Augment the flow while there is a path from source to sink 
    while (bfs(rGraph, S, T, N, parent)) 
    { 
        // Find minimum residual capacity of the edhes along the 
        // path filled by BFS. Or we can say find the maximum flow 
        // through the path found. 
        int path_flow = INT_MAX; 
        for (v=T; v!=S; v=parent[v]) 
        { 
            u = parent[v]; 
            path_flow = min(path_flow, rGraph[u][v]); 
        } 
  
        // update residual capacities of the edges and reverse edges 
        // along the path 
        for (v=T; v != S; v=parent[v]) 
        { 
            u = parent[v]; 
            rGraph[u][v] -= path_flow; 
            rGraph[v][u] += path_flow; 
        } 
    } 
  
    // Flow is maximum now, find vertices reachable from s 
    vector<bool> visited(N); 
    dfs(rGraph, S, N, visited); 
    
    vector<int> res;
  
    // Returning all edges that are from a reachable vertex to 
    // non-reachable vertex in the original graph 
    for (int i = 0; i < N; i++) 
      for (int j = 0; j < N; j++) 
         if (visited[i] && !visited[j] && A[i][j]) {
             res.push_back(i);
             res.push_back(j);
         }
    if(res.size()==0){
        res.push_back(-1);
    }
    return res; 
}