class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mpri = INT_MAX,mpro=0;
        for(int i=0; i<p.size(); i++){
            mpri = min(mpri,p[i]);
            mpro = max(mpro,p[i]-mpri);
        }
        return mpro;
    }
};