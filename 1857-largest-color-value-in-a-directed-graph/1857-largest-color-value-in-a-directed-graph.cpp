class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int ans=1;
        int n=colors.size();
        vector <vector <int>> dp(n,vector <int> (26,0));
        vector <int> adj[n];
        vector <int> ind(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            ind[v]++;
        }
        queue <int> q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
                int val=colors[i]-'a';
                dp[i][val]=max(dp[i][val],1);

            }
        }
        int ct=0;
        while(!q.empty()){
            int sz=q.size();
            ct+=sz;
            for(int i=0;i<sz;i++){
                int curr=q.front();
                q.pop();

                for(int x: adj[curr])
                {
                    ind[x]--;
                    int val=colors[x]-'a';
                    if(ind[x]==0){
                        q.push(x);
                    }
                    for(int j=0;j<26;j++){
                        if(val==j){
                            dp[x][j]=max(dp[x][j],dp[curr][j]+1);
                            ans=max(ans,dp[x][j]);
                        }
                        else{
                            dp[x][j]=max(dp[x][j],dp[curr][j]);
                            ans=max(ans,dp[x][j]);
                        }
                    }
                }

              
            }
        }
        if(ct==n){
            return ans;
        }
        else{
            return -1;
        }

    }
};