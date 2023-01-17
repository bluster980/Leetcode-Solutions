class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> v(n,vector<int> (n,0));
        for(int i=0; i<q.size(); i++){
            for(int j=q[i][0]; j<=q[i][2]; j++){
                // cout<<j<<q[i][1]<<endl;
                v[j][q[i][1]]++;
                if(q[i][3]+1 < n){
                    v[j][q[i][3] + 1]--;
                }
            }
        }
        for(int i=0; i<v.size(); i++){
            for(int j=1; j<v[i].size(); j++)
            {
                v[i][j]+=v[i][j-1];
                // cout<<v[i][j]<<" ";
            }
            // cout<<endl;
        }
        // for(int i=1; i<q.size(); i++){
        //     v[i][q[i][0]]++;
        //     if(q[i][2]+1 < n)
        //         v[i][q[i][2] + 1]--;
        // }
        // for(int i=1; i<v.size(); i++){
        //     for(int j=1; j<v[i].size(); j++){
        //         v[i][j]+=v[i][j-1];
        //     }
        // }
        return v;
    }
};