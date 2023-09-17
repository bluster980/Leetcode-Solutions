class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<vector<int>> W(n , vector<int>(n , 150));
        for(int i = 0 ; i < n ; i++)
            W[i][i] = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j : graph[i]){
                W[i][j] = 1;
            }
        }
        
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                for(int k = 0 ; k < n ; k++){
                    W[i][j] = min(W[i][j] , W[i][k] + W[k][j]);
                }
            }
        }
        
        vector<vector<int>> dp(1<<n , vector<int>(n, 150));
        
        for(int i = 0 ; i < n ; i++){
            dp[1<<i][i] = 0;
        }
        
        for(int mask = 0 ; mask < 1<< n ; mask++){
            
            vector<int> nz;
            for(int j = 0 ; j < n; j++){
                if(mask & (1 << j))
                    nz.push_back(j);
            }
            
            for(int j : nz){
                for(int k : nz){
                    if(j != k){
                    int neib = dp[mask ^ (1 << j)][k];
                    dp[mask][j] = min(dp[mask][j] , neib + W[k][j]);
                    }
                }
            }
            
        }
        
        int res = 150;
        
        for(int i = 0 ; i < n ; i++)
            res = min(res, dp.back()[i]);
            
        return res;
    }
};