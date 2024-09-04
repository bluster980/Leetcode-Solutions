class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans=0;
        vector<unordered_map<int,set<int>>> obs(2);
        for (auto &obst: obstacles) {
            obs[0][obst[0]].insert(obst[1]);
            obs[1][obst[1]].insert(obst[0]); }
        vector<int> coord{0,0}; size_t axis=1; bool dirn=true;
        for (int cmd: commands) { 
            if (cmd==-1) {dirn=!(axis^dirn); axis^=1; }
            else if (cmd==-2) { dirn^=axis; axis^=1; }
            else { 
                int lwr=min(coord[axis]+(dirn*2-1),coord[axis]+(dirn*2-1)*cmd);
                int upr=max(coord[axis]+(dirn*2-1),coord[axis]+(dirn*2-1)*cmd);
                auto lptr=lower_bound(obs[axis^1][coord[axis^1]].begin(), obs[axis^1][coord[axis^1]].end(), lwr);
                auto uptr=upper_bound(obs[axis^1][coord[axis^1]].begin(), obs[axis^1][coord[axis^1]].end(), upr);
                if (lptr==uptr) { coord[axis]+=(dirn*2-1)*cmd; }
                else {coord[axis]=dirn?*lptr-1:*(prev(uptr))+1; }
                cout << lwr << "," << upr << "," << coord[0] << "," << coord[1] << endl;
                 }
            
            ans=max(ans, coord[0]*coord[0]+coord[1]*coord[1]); }
        return ans; 
    } 
};