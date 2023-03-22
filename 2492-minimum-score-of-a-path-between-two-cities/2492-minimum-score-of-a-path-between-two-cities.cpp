class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map <int, vector<pair<int,int>>> umap;
        for(auto a: roads){
            umap[a[0]].push_back({a[1], a[2]});
            umap[a[1]].push_back({a[0], a[2]});
        }
        
        queue<int> q;
        vector<bool> visited (n, false);
        q.push(1);
        int mini = INT_MAX;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            visited[x] = true;
            vector<pair<int,int>> v = umap[x];
            for(int i=0; i<v.size(); i++){
                if(visited[v[i].first] == false){
                    q.push(v[i].first);
                    mini = min(v[i].second , mini); 
                }
            }
        }

        return mini;
    }
};