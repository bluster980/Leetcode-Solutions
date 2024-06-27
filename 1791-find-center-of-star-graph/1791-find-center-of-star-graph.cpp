class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<vector<int>> v(edges.size()+2);
        for(int i=0; i<edges.size(); i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        int maxx = 0,ans=0;
        // for(int i=0; i<v.size(); i++){
        //     for(int x:v[i])
        //         cout<<x<<" ";
        //     cout<<endl;
        // }
        for(int i=1; i<v.size(); i++){
            if(v[i].size() > maxx){
                ans = i;
                maxx = max((int)v[i].size(),maxx);
            }
        }
        return ans;
    }
};