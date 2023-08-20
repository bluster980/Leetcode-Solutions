class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> v(n);
        for(int i=0; i<roads.size(); i++){
            v[roads[i][0]].insert(roads[i][1]);
            v[roads[i][1]].insert(roads[i][0]);
        }
        int ans = 0;
        for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
                int curr = v[i].size() + v[j].size();
                if(v[j].count(i)) --curr;
                ans = max(ans,curr);
            }
        }
        return ans;
    }
};