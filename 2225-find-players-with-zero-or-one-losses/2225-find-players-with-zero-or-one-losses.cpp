class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        vector<vector<int>> vp(2);
        map<int,int> win,los;
        for(int i=0; i<m.size(); i++){
            win[m[i][0]]++; los[m[i][1]]++;
        }
        for(auto xx:win){
            // cout<<xx.first<<" "<<xx.second<<endl;
            if(los.find(xx.first) == los.end()){
                vp[0].push_back(xx.first);
            }
            else if(los[xx.first] == 1){
                vp[1].push_back(xx.first);
            }
        }
        for(auto xx:los){
            if(win.find(xx.first) == win.end() && xx.second==1){
                vp[1].push_back(xx.first);
            }
        }
        sort(vp[0].begin(),vp[0].end());
        sort(vp[1].begin(),vp[1].end());
        // for(int i=0; i<vp.size(); i++){cout<<endl;
        //     for(int j=0; j<vp[i].size(); j++){
        //         cout<<vp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;if(vp[i].size() == 0){
        // for(auto xx:los){
        //     cout<<xx.first<<" "<<xx.second<<endl;
        // }
        return vp;
    }
};