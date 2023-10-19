//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int n, vector<int> adj[], int x) {
	    queue<pair<int, int>> q;
	    int curNode, curLvl;
	    unordered_map<int, int> m;
	    
	    q.push({0, 0}); 
	    while(q.size()) {
	        curNode = q.front().first, curLvl = q.front().second;
	        q.pop();
	        m[curNode]++;
	        
	        for(int nbr : adj[curNode]) {
	            if(nbr == x) return curLvl + 1;
	            if(!m[nbr]) q.push({nbr, curLvl + 1});
	        }
	    }
	    
	    return -1;
}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends