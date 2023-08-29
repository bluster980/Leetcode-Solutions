class Solution {

int factorial(int n){
     return (n==1 || n==0) ? 1: n * factorial(n - 1);
}

public:
    vector<vector<int>> permuteUnique(vector<int>& v) {
        vector<vector<int>> vv;
        int range = factorial(v.size());
        // vv.push_back(v);
        set<vector<int>>s;
        for(int i=0; i<range; i++){
            next_permutation(v.begin(),v.end());
            // vv.push_back(v);
            s.insert(v);
        }
        for(auto x:s){
            vv.push_back(x);
        }
        // vv.erase(unique(vv.begin(),vv.end()),vv.end());
        // cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
        return vv;
    }
};