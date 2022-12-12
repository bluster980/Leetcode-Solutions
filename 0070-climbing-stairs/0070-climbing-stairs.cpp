class Solution {
public:
    int climbStairs(int n) {
        vector<int> v(n);
        if(n==1) return 1;
        v[0] = 1,v[1] = 1;
        int ans;
        for(int i=2; i<n; i++){
            v[i] = v[i-1]+v[i-2];
        }
        return v[v.size()-1]+v[v.size()-2];
    }
};