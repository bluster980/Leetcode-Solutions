class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int row=m[0].size(),col=m.size();
        vector<pair<int,int>> vp; vector<int> visc(row,0),visr(col,0);
        for(int i=0; i<col; i++){
            for(int j=0; j<row; j++){
                if(m[i][j] == 0){
                    vp.push_back({i,j});
                }
            }
        }
        for(int i=0; i<vp.size(); i++){
            if(visr[vp[i].first] == 0)
            {
                for(int j=0; j<row; j++){
                    m[vp[i].first][j] = 0; visr[vp[i].first] = 1;
                }
            }
            if(visc[vp[i].second] == 0){
                for(int j=0; j<col; j++){
                    m[j][vp[i].second] = 0; visc[vp[i].second] = 1;
                }
            }
            
        }
    }
};