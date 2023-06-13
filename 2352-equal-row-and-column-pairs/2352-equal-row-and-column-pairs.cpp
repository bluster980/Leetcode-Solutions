class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mp,mp2; int count = 0;
        for(int i=0; i<grid.size(); i++){
            vector<int> tmp,tmp2;
            for(int j=0; j<grid[i].size(); j++){
                tmp.push_back(grid[i][j]);
                tmp2.push_back(grid[j][i]);
            }
            mp[tmp]++; mp2[tmp2]++;
        }
        for(auto xx:mp){
            if(mp2.find(xx.first)!=mp2.end()){
                count += (mp2[xx.first]*xx.second);
            }
        }
        return count;
    }
};