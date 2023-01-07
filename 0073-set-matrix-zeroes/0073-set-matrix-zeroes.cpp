class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int row=m[0].size(),col=m.size();
        vector<pair<int,int>> vp; vector<int> visr(row),visc(col);
        for(int i=0; i<col; i++){
            for(int j=0; j<row; j++){
                if(m[i][j] == 0){
                    vp.push_back({i,j});
                }
            }
        }
        // for(int i=0; i<vp.size(); i++){
            // cout<<vp[i].first<<" "<<vp[i].second<<endl;
        // }
        // cout<<"#####"<<endl;
        for(int i=0; i<vp.size(); i++){
            for(int j=0; j<row; j++){
                // cout<<vp[i].first<<" "<<j<<endl;
                // cout<<m[vp[i].first][j]<<" ";
                m[vp[i].first][j] = 0;
            }
            for(int j=0; j<col; j++){
                m[j][vp[i].second] = 0;
                 // cout<<j<<" "<<vp[i].second<<endl;
            }
            // cout<<endl;
        }
        // cout<<endl;
    }
};