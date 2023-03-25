class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>&v, vector<int>&vv) {
        vector<vector<int>> ans; int i=0;
        // if(v.size()==0) return {{vv[0],vv[1]}};
        // while(i<v.size()){
            while(i<v.size() && v[i][1] < vv[0]){
                ans.push_back(v[i]); i++;
            }
            while(i<v.size() && vv[1] >= v[i][0]){
                vv[0] = min(v[i][0],vv[0]);
                vv[1] = max(v[i][1],vv[1]); 
                i++;
            }
            ans.push_back(vv);
            while(i<v.size()){
                ans.push_back(v[i]); i++;
            }
        // }
        return ans;
    }
};