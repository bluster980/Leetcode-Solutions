class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>&v) {
        vector<vector<int>> ans;
        sort(v.begin(),v.end());
        for(int i=0; i<v.size(); i++){
            int x = v[i][0], y = v[i][1];
            while((i+1 < v.size()) && y >= v[i+1][0]){
                y = max(y,v[i+1][1]); i++;
            }
            ans.push_back({x,y});
        }
        return ans;
    }
};